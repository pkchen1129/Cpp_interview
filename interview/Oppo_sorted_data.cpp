/*
Struct Data;

Data.type- > acc / gyr
(Double)  Data.time -> time

Acc: std::vector<Data> ---> sorted by time
Gyr: std::vector<Data> -->sorted by time
Mag: std::vector<Data>-->sorted by time
*/

using namespace std;
vector<Data> func (vector<Data>& Acc, vector<Data>& Gyr) {
    int p1 = 0 , p2 = 0;
    vector<Data> ans;
        while(p1 < Acc.size() || p2 < Gyr.size() ){
            if (Acc[p1].t < Gyr[p2].t) {
        ans.push_back(Acc[p1]);
        p1++;
    }
        else {
            ans.push_back(Gyr[p2]);
            p2++;
        }
    }

    if (p1 == Acc.size()) {
        while (p2 != Gyr.size()) {
                ans.push_back(Gyr[p2++]);
        }
    }
        else {
            while (p1 != Acc.size()) {
                    ans.push_back(Acc[p1++]);
            }
        }
    return ans;

}







