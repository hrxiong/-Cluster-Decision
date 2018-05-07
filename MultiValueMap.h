//
//  MultiValueMap.h
//  腾飞科创Model
//
//  Created by leavesyoung on 2018/5/2.
//  Copyright © 2018年 leavesyoung. All rights reserved.
//

#ifndef MultiValueMap_h
#define MultiValueMap_h
#include <map>
#include <vector>
using namespace std;

/*******************************************
 *this template class is used to simulate
 *tables in the database.The key in the map
 *is the primary key in the table.The value
 *in the map is the other attributes in the
 *table.You can use the subscript to find
 *certain attribute.Since it uses map,you may
 *need to overload operators before using it.
 *******************************************/

template <class K,class V>
class MultiValueMap {
    map<K,vector<V>> table;
    int AttributeNumber;
    
    public:
    MultiValueMap(int AttibuteNumber){
        this->AttributeNumber=AttributeNumber;
        table.clear();
    }
    ~MultiValueMap(){}
    
    //add a tuple
    int addTuple(K key,vector<V> value){
        if(value.size()!=AttributeNumber) return -1;
        //error:the number of arrtibute is not correct.
        else if(containsKey(key)) return 1;
        //warning:the key already exists.Replace it?
        else table[key]=value;
        return 0;
    }
    
    //delete a tuple
    int deleteTuple(K key){
        if(!containsKey(key)) return -1;
        //error:can't find the key.
        else table.erase(key);
        return 0;
    }
    
    //set an attribute
    int setAttribute(K key,int index,V value){
        if(!containsKey(key)) return -1;
        //error:can't find the key.
        else (table[key])[index]=value;
        return 0;
    }
    
    //set a tuple
    int setTuple(K key,vector<V> value){
        if(value.size()!=AttributeNumber) return -1;
        //error:the number of arrtibute is not correct.
        else if(!containsKey(key)) return -1;
        //error:can't find the key.
        else table[key]=value;
        return 0;
    }
    
    //get the attribute
    V getAttribute(K key,int index){
        if(!containsKey(key)) throw domain_error("can't find the key.");
        //error:can't find the key.
        else return table[key][index];
    }
    
    //get the tuple
    vector<V> getTuple(K key){
        if(!containsKey(key)) throw domain_error("can't find the key.");
        //error:can't find the key.
        else return table[key];
    }
    
    //judge if the map is empty
    bool isEmpty(){
        return table.empty();
    }
    
    //judge if the map contains the key
    bool containsKey(K key){
        return table.find(key)!=table.end();
    }
    
    //get the size of the map
    int size(){
        return table,size();
    }
    
    //clear the map
    void clear(){
        table.clear();
    }
};
#endif /* MultiValueMap_h */
