
#include <iostream>
#include <set>
#include <assert.h>
using namespace std;

// supposed it is one-to-one relationship between key and value
// build a struct to store the key-value pair
template <typename keyType, typename valueType>
struct KeyValuePair {
            keyType key;
            valueType value;
            
            KeyValuePair (keyType k): key(k) {}
            KeyValuePair (keyType k, valueType v): key(k), value(v) {}
            
            // operator < is used to determine the order in set
            // operator < is also used in set::find()
            bool operator < ( const KeyValuePair& input) const {
                return key < input.key;
            }
        };

template <typename keyType, typename valueType>
class Map {
    private:
        // use two sets to fulfill the manipulation on key-value pair given either key or value
        // keysToValuesSet is used when the key is provided
        // valuesToKeysSet is used when the value is provided
        set<KeyValuePair<keyType, valueType>> keysToValuesSet;
        set<KeyValuePair<valueType, keyType>> valuesToKeysSet;
        
    public:
        Map() {}
        
        ~Map() {}
        
        // insert can be used to push new pair into map or update the existed pair in the map 
        bool insert (pair<keyType, valueType> input) {
        // return true when there is no existed identical key-value pair in the map and the input pair is inserted into map
        // return false when there is an existed identical key-value pair in the map and the input pair isn't inserted into map
            return insert(input.first, input.second);
        }
        
        bool insert (keyType key, valueType value) {
            // time complexity : O(log n) because set is a red black tree
            // space complexity : O(1) 
            KeyValuePair<keyType, valueType> keyToValue(key, value);
            KeyValuePair<valueType, keyType> valueToKey(value, key);
            
            // if the map is empty, insert input pair
            if (keysToValuesSet.empty()) {
                keysToValuesSet.insert(keyToValue);
                valuesToKeysSet.insert(valueToKey);
                return true;
            }
            
            // check whether the key exists in the map
            auto it = keysToValuesSet.find(keyToValue);
            if (it != keysToValuesSet.end()) {
                // if the existed key-value pair matches the input key-value pair, return false;
                if (it->value == value)
                    return false;
                    
                // if the key exists but the value isn't the same, erase the key-value pair in both keysToValuesSet and valuesToKeysSet
                valuesToKeysSet.erase(KeyValuePair<valueType, keyType> (it->value));
                keysToValuesSet.erase(it);
            }
            else {
                // Even though the key doesn't exit in the map,
                // we still need to check whether the value exists in the map
                
                // Since we supposed it is one-to-one relationship between key and value,
                // we have to erase the key-value pair when the value already exists in the map
                auto it2 = valuesToKeysSet.find(valueToKey);
                if (it2 != valuesToKeysSet.end()) {
                    keysToValuesSet.erase(KeyValuePair<keyType, valueType> (it2->value));
                    valuesToKeysSet.erase(it2);
                }
            }
            
            // push input key-value pair in both keysToValuesSet and valuesToKeysSet
            keysToValuesSet.insert(keyToValue);
            valuesToKeysSet.insert(valueToKey);
            return true;
        }
        
        // try to erase the key-value pair given key
        bool EraseWithKey (const keyType key) {
            // if the key exists in the map, 
            // return true and erase the key-value pair in both keysToValuesSet and valuesToKeysSet
            // if the key doesn't exist in the map return false
            
            // time complexity : O(log n) because set is a red black tree
            // space complexity : O(1) 
            KeyValuePair<keyType, valueType> keyToValue(key);
            auto it = keysToValuesSet.find(keyToValue);
            if (it != keysToValuesSet.end()) {
                valuesToKeysSet.erase(KeyValuePair<valueType, keyType> (it->value));
                keysToValuesSet.erase(it);
                return true;
            }
            return false;
        }
        
        // try to erase the key-value pair given value
        bool EraseWithValue (const valueType value) {
            // if the value exists in the map, 
            // return true and erase the key-value pair in both keysToValuesSet and valuesToKeysSet
            // if the value doesn't exist in the map return false
            
            // time complexity : O(log n) because set is a red black tree
            // space complexity : O(1) 
            KeyValuePair<valueType, keyType> valueToKey(value);
            auto it = valuesToKeysSet.find(valueToKey);
            if (it != valuesToKeysSet.end()) {
                keysToValuesSet.erase(KeyValuePair<keyType, valueType> (it->value));
                valuesToKeysSet.erase(it);
                return true;
            }
            return false;
        }
        
        // find the value given key
        pair<bool, const valueType> FindWithKey (const keyType key) const{
            // the first element indicate whether the key is found in the map
            // if the key is found, the second element store the correct value
            // if the key isn't found, the second element store the last value in the keysToValuesSet
            
            // time complexity : O(log n) because set is a red black tree
            // space complexity : O(1) 
            KeyValuePair<keyType, valueType> keyToValue(key);
            auto it = keysToValuesSet.find(keyToValue);
            if (it == keysToValuesSet.end()) {
                return {false, keysToValuesSet.cbegin()->value};
            }
            else {
                return {true, it->value};
            }
        }
        
        // find the key given value
        pair<bool, const keyType> FindWithValue (const valueType value) const{
            // the first element indicate whether the value is found in the map
            // if the value is found, the second element store the correct key
            // if the value isn't found, the second element store the last key in the valuesToKeysSet
            
            // time complexity : O(log n) because set is a red black tree
            // space complexity : O(1) 
            KeyValuePair<valueType, keyType> valueToKey(value);
            auto it = valuesToKeysSet.find(valueToKey);
            if (it == valuesToKeysSet.end()) {
                return {false, valuesToKeysSet.cbegin()->value};
            }
            else {
                return {true, it->value};
            }
        }
        
        // return the number of key-value pairs in the map
        int size () {
            return keysToValuesSet.size();
        }
        
        // check whether the map is empty
        bool empty() {
            return keysToValuesSet.empty();
        }
};


int main()
{
    Map<string, int> m; // initialize a map
    assert(m.insert(make_pair("abc", 123))); // insert( {"abc", 123} )
                                             // new pair is inserted, so Map::insert() should return true;
                                             
                                             
    auto it = m.FindWithKey("abc"); // find value given key "abc"
                                    // return pair<bool, valueType>
    assert(it.first);   // key "abc" should be found, i.e., it.first should be equal to true
    assert(it.second == 123);    // check whether the value is equal to 123
    
    
    assert(m.insert("abc", 999));    // update the value with respect to key "abc"
                                     // there is no identical pair, so Map::insert() should return true;
                                     
                                     
    auto it2 = m.FindWithKey("abc");
    assert(it2.first);  // key "abc" should be found, i.e., it2.first should be equal to true
    assert(it2.second == 999);   // check whether the value is equal to 999
    
    
    auto it3 = m.FindWithValue(999);    // find key given value 999
                                        // return pair<bool, keyType>
    assert(it3.first);  // value 999 should be found, i.e., it3.first should be equal to true
    assert(it3.second == "abc");    // check whether the key is equal to "abc"
    
    
    auto it4 = m.FindWithValue(123); // find key given value "123"
    assert(!it4.first); // since the pair {"abc", 123} was changed to {"abc", 999}, 
                        // there is no key with respect to value 123
                                
                                
    assert(m.insert("ABC", 999));    // update the key with respect to value 999
                                     // there is no identical pair, so Map::insert() should return true;
                                     
                                     
    auto it5 = m.FindWithKey("abc");
    assert(!it5.first);  // there is no key "abc", i.e., it5.first should be equal to false
    
    
    int size = m.size();
    assert(size == 1);  // the size right now should be one
                        // only {"ABC", 999} is in the map 
    
    
    assert(!m.insert("ABC", 999));   // insert an identical pair {"ABC", 999} into map
                                     // Map::insert() should return false because of another identical pair is in the map
                                     
                                     
    size = m.size();
    assert(size == 1);  // the size is still one
                        // only one {"ABC", 999} is in the map 
                        
    
    auto it6 = m.FindWithKey("ABC");   // find value given key "ABC"
    assert(it6.first); // since there is no key "def" in the map, the it6.first should be false
    assert(it6.second == 999); // since there is no key "def" in the map, the it6.first should be false
    
    
    assert(m.insert(make_pair("def", 456)));    // Insert( {"def", 456} )
                                                // new pair is inserted, so Map::insert() should return true;
                                                
                                                
    auto it7 = m.FindWithValue(456);    // find key given value "456"
    assert(it7.first);  // value 456 should be found, i.e., it7.first should be equal to true
    assert(it7.second == "def");    // check whether the key is equal to "def"
    
    
    size = m.size();
    assert(size == 2);  // there should be two pair {"ABC", 999} and {"def", 456}  in the map  
    
    
    assert(m.EraseWithKey("def"));  // erase the pair {"def", 456} given key "def"
                                    // since key "def" is in the map, true should be returned 
                                
                                    
    auto it8 = m.FindWithKey("def");   
    assert(!it8.first);  // check whether pair {"def", 456} was erased
    
    
    size = m.size();
    assert(size == 1);  // there should be one pair {"ABC", 999} remaining in the map   
    
    
    assert(m.EraseWithValue(999));  // erase the pair {"ABC", 999} given value 999
                                    // since value 999 is in the map, true should be returned
                                            
                                            
    auto it9 = m.FindWithKey("ABC"); 
    assert(!it9.first);  // check whether pair {"ABC", 999} was erased 
    
    
    assert(m.empty());  // the map shpuld be empty
    return 0;
}