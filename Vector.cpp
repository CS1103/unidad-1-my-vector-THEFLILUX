//
// Created by rudri on 3/29/2019.
//

#include "Vector.h"

namespace UTEC {
    void vector::push_back(int &value) {
        _size++;
        if(_arr == nullptr){
            _arr= new int[_size];
            _arr[0]=value;
        }
        else{
            int *_arr2 = new int[_size];
            for(int k=0; k<_size-1;k++){
                _arr2[k]=_arr[k];
            }
            _arr2[_size-1]=value;
            delete [] _arr;
            _arr = _arr2;
        }
    }

    void vector::pop_back(){
        _size--;
        if(_arr == nullptr){
            _arr= new int[_size];
            for(int i=0;i<_size;i++){
                _arr[i]=i;
            }
        }
        else{
            int *_arr2 = new int[_size-1];
            for(int k=0; k<_size-1;k++){
                _arr2[k]=_arr[k];
            }
            delete [] _arr;
            _arr = _arr2;
        }
    }

    void vector::insert(int pos, const int &value) {
        _size++;
        if(_arr== nullptr){
            _arr= new int[_size];
            _arr[0]=value;
        }
        else{
            int *_arr2 = new int[_size+1];
            for(int k=0; k<=pos;k++){
                if(k==pos){
                    _arr2[k] = value;
                }
                else{
                    _arr2[k] = _arr[k];
                }
            }
            for(int k=pos+1;k<=_size+1;k++){
                _arr2[k] = _arr[pos];
                pos++;
            }
            delete [] _arr;
            _arr = _arr2;
        }
    }

    vector::vector() : _arr{nullptr}, _size(0) {}
    vector::~vector() = default;

    int vector::size() {return _size;}

    int vector::get_item(int i) {return _arr[i];}
}