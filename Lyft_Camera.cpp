Matrix3d R_cam2car;
Vector3d t_cam2car;
Vector2d pixel;
Matrix3d K;
Plane plane_in_vehicle;

struct Line {
    Vector3d point;
    Vector3d direction;
};
struct Plane {
    Vector3d point;
    Vector3d normal_direction;
};


/**
 * @brief Transform the pixel value from pixel frame to camera frame. 
 *        We then can get the ray from camera center(0,0,0) to cone(X,Y,Z) 
 *        in camera frame
 * 
 * @param pixel                     Vector2d  [u, v]
 * @param K                         Matrix3d  Intrinsic matrix with information 
 *                                            of focal length, skew value etc.
 * @return cam_to_cone_ray          Line      Ray of the line from camera center to cone
 */
Line pixel2cam (Vector2d pixel, Matrix3d K) {}


/**
 * @brief Transform the ray from camera frame to car frame.
 * 
 * @param cam_to_cone_ray           Line      The ray from pixel2cam()
 * @param R_cam2car                 Matrix3d  The rotation matrix
 * @param t_cam2car                 Vector3d  The translation value
 * @return cam_to_cone_ray_vehicle  Line      The ray with respect to 
 *                                            car coordinate
 */
Line cam2car(Line cam_to_cone_ray, Matrix3d R_cam2car, Matrix3d t_cam2car) {}


/**
 * @brief Get the intersect point of the ray and the plane
 *        (Since they're all in same coordinate)
 * 
 * @param plane_in_vehicle          Plane     The plane of the ground w.r.t 
 *                                            vehicle frame 
 * @param cam_to_cone_ray_vehicle   Line      The ray from camera center to cone
 *                                            w.r.t vehicle frame
 * @return P_car                    Vector3d  Point of the cone w.r.t car frame
 */
Vector3d intersect(Plane plane_in_vehicle, Line cam_to_cone_ray_vehicle){}


/**
 * @brief Get the distance by gaining the L2 norm of the P_car
 * 
 * @param P_car                     Vector3d
 * @return distance                 float 
 */
float L2norm(Vector3d P_car) {}


float get_distance (Vector2d pixel, Matrix3d R_cam2car, Matrix3d t_cam2car, Plane plane_in_vehicle, Matrix3d K) {
    float distance;
    // Transform the u, v from pixel frame to camera frame
    Line cam_to_cone_ray = pixel2cam(pixel, K);
    
    // Transform the ray from camera frame to car frame.
    // We'll get the ray w.r.t car center
    Line cam_to_cone_ray_vehicle = cam2car(cam_to_cone_ray, R_cam2car, t_cam2car);

    // Get the intersect of the ray and plane
    Vector3d P_car = intersect(plane_in_vehicle, cam_to_cone_ray_vehicle);
    
    // Get the distance by L2norm
    distance = L2norm(P_car);
    
    return distance;
}