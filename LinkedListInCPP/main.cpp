#include <iostream>
using namespace std;
template <typename T>
class node {
  public:
    T data;
    node<T> *next;

    node()  {
    next = NULL;
    }
    node(const T& value, node<T> *ptr = NULL) {
     data = value;
     next = ptr;

    }

};

// Linked list class
template <typename T>
class List {
   private:

    node<T>* head;
    node<T>* tail;
    int Size;

   public:

    List() {

      head = tail = new node<T>();
      Size = 0;
    }

    List (T value, int initial_size){
      head = tail = new node<T>;
      Size = 0;
      for(int i=0; i< initial_size; i++)
        Insert(value, Begin());

      }





    // Inner class iterator
    class Iterator {
    friend class List;
    private:

      node<T> *myNode;


      //private constructor
      Iterator(node<T> *newPtr)  {
        myNode = newPtr;
      }
    public:
      Iterator()
       {
         myNode = NULL;
       }

      // overload for operators
      bool operator!=(const Iterator& i)  {
        return myNode != i.myNode;
      }


      T& operator*() const {
        return myNode->next->data;
      }



      Iterator operator++() {
        myNode = myNode->next;
        return *this;
      }
      Iterator operator--()
      {
          return myNode;
      }

    };


// List functions that need iterator class
    Iterator Begin() {
      return Iterator(head);
    }

    Iterator End() {
      return Iterator(tail);
    }

    Iterator Insert(const T& value,Iterator position) {
      Size++;
      node<T>* newNode = new node<T>(value, position.myNode->next);
      if (position.myNode == tail)
        tail = newNode;

      position.myNode->next = newNode;
      return position;
    }

    Iterator Erase(Iterator position) {
      Size--;
      node<T> *ENode = position.myNode->next;
      position.myNode->next = position.myNode->next->next;
      if (ENode == tail)
        tail = position.myNode;
      delete ENode;
      return position;
    }

   List<T> operator=(const List& rhs)
{
    if (this == &rhs)
        return *this;

    List<T> result;
    result.Size = rhs.Size;
    Iterator iter2(rhs.head);
    for(int i=0; i<Size; i++)
    {
        Insert(*iter2, result.End());
        ++iter2;
    }
    return result;
}

   int getSize (){
   return Size;
   }

   ~List() {
      while (head->next != NULL) {
        node<T>* temp = head;
        head = head->next;
        delete temp;
      }
      delete head;
    }
};
int main()
{
  List<int> L(2,4);

  auto i= L.Begin();
  ++i;
  L.Insert(5,i);



 List<int> L2 = L;
     for(auto itr = L2.Begin();itr != L2.End();++itr)
     cout << *itr << endl;

  cout<<"***************************************"<<endl;
  L.Erase(i);
  for(auto itr = L.Begin();itr != L.End();++itr)
     cout << *itr << endl;

  return 0;
}
