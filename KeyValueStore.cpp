#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;
class KeyValueStore{
private:
    // <key, map<version_num, value>>
    unordered_map<string, map<int, string>> map;
    int version;
public:
    KeyValueStore(){
        version = 0;
    }
    int put (string key, string val) {
        if (!map.count(key)) {
            map[key].insert({version, val});
        }
        
        cout << "PUT (#:" << ++version << ") " << key << " = "<< val<< endl;
        return version;
    }
    
    // Get latest version!
    string get (string key) {
        if (!map.count(key)) {
            cout << "GET " << key << " = <NULL>" << endl;
            return NULL;
        }
        // Get the biggest version!
        cout << "GET " << key << " = " << map[key].rbegin()->second << endl;
        return map[key].begin()->second;
    }
    
    string get (string key, int v) {
        if (!map.count(key)) {
            cout << "GET " << key << "(#" << v << ") = <NULL>" << endl;
            return NULL;
        }
        string value;
        if (map[key].count(v)) {
            value = map[key][v];
        } 
        else {
            // find the largest but smaller than the input version
            auto it = map[key].lower_bound(v);
            // 遠小於他的key ex: version = 0
            if (!map[key].count(v)) {
            // if (it == map[key].begin()) {
                cout << "GET " << key << "(#" << v << ") = <NULL>" << endl;
                return NULL;
            }
            value = --it->second;
            // value = map[key][v];
        }
 
        cout << "GET " << key << "(#" << v << ") = " << value << endl;
        return value;
    }
};
int main() {
    KeyValueStore a;
    a.put("key1", "5");
    a.put("key2", "6");
    a.get("key1");
    
    a.get("key1", 1);
    a.get("key2", 2);
    a.put("key1", "7");
    a.put("key1", "8");
    
    
    a.get("key1", 1);
    a.get("key1", 2);
    a.get("key1", 3);
    a.get("key1", 4);
    
    
    // a.get("key4");
    // a.get("key1", 4);
    
    
    
    
    return 0;
}
