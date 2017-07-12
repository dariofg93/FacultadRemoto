#pragma once

#include <string>
#include <list>
#include <iostream>
#include <sstream>

using namespace std;

template <class ELEM_TYPE>
class List {
private:
    list<ELEM_TYPE> inner;

    void validateNotNil() const{
        if (isNil()) {
            string error("The List is NIL!!!");
            cout << error << endl;
            throw error;
        }
    }

public:
    bool operator == (const List& l1) const {
        return inner == l1.inner;
    }

    bool operator != (const List& l1) const {
        return !((*this) == l1);
    }


    List<ELEM_TYPE> Cons(ELEM_TYPE x) const {
        List<ELEM_TYPE> copy = *(this);
        copy.inner.push_front(x);
        return copy;
    }

    List<ELEM_TYPE> Snoc(ELEM_TYPE x) const {
        List<ELEM_TYPE> copy = *(this);
        copy.inner.push_back(x);
        return copy;
    }


    bool isNil() const{
        return inner.empty();
    }

    ELEM_TYPE last() const {
        validateNotNil();
        return inner.back();
    }

    ELEM_TYPE head() const {
       validateNotNil();
       return inner.front();
    }

    List<ELEM_TYPE> tail() const {
        validateNotNil();
        List<ELEM_TYPE> copy = *(this);
        copy.inner.pop_front();
        return copy;
    }

    List<ELEM_TYPE> init() const {
        validateNotNil();
        List<ELEM_TYPE> copy = *(this);
        copy.inner.pop_back();
        return copy;
    }

    string toStringList(const string & separator) const{
        stringstream b;
        if (isNil()) {
            b << "[]";
        } else {
            List<ELEM_TYPE> ys = *this;
            b << "[ ";
            b <<  (ys.head());
            ys = ys.tail();
            while (! ys.isNil()) {
                b <<  separator;
                b <<  (ys.head());
                ys = ys.tail();
            }
            b << " ]";
        }
        return b.str();
    }

    string toStringList() const{
        return toStringList(", ");
    }

    string toFormattedStringList() const{
        return toStringList("\n");
    }

    void PrintList() const {
        cout << toStringList();
    }
};

template <class ELEM_TYPE>
std::ostream& operator<<(std::ostream& out,const List<ELEM_TYPE> &xs){
    out << xs.toStringList();
    return out;
}


// La lista vacia
template <class ELEM_TYPE>
List<ELEM_TYPE> Nil() {
    return List<ELEM_TYPE>();
}


#define Cons(x,xs) (xs).Cons(x)

#define Snoc(xs,x) (xs).Snoc(x)

#define isNil(xs) (xs).isNil()

#define head(xs) (xs).head()

#define tail(xs) (xs).tail()

#define last(xs) (xs).last()

#define init(xs) (xs).init()

#define toStringList(xs) (xs).toStringList()

#define toFormattedStringList(xs) (xs).toFormattedStringList()

#define PrintList(xs) (xs).PrintList()


