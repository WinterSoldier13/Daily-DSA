#include<iostream>
#include <bits/stdc++.h> 
#include<math.h>
using namespace std;


class LRUCache {
public:
class Node
{
     public:
     int key;
     int value;
     Node* next;
     Node* prev;
};

int cap;
unordered_map<int,Node*> map;
Node* head = new Node();
Node* tail = new Node();
int current_size;
void popFront()
     {
          head->next->prev =NULL;
          head = head->next;
     }
     void popBack()
     {
          tail->prev->next = NULL;
          tail = tail->prev;
     }
     void popNode(Node* node)
     {
          if(tail==node)
          {
               tail = node->prev;
               tail->next = NULL;
          }
          else
          {
               Node* n = node->next;
               Node* p = node->prev;
               n->prev = p;
               p->next = n;
               
          }
          

     }

     void pushFront(Node* node)
     {
          if(current_size==0)
          {
               head = node;
               tail = node;
          }
          else
          {
               head->prev = node;
               node->next = head;
               node->prev = NULL;
               // tail = head;
               head = node;
                    
          }
     }



    
    LRUCache(int capacity) 
    {
         cap = capacity;
         current_size=0;
    }
    
    int get(int key) 
    {
         if(map.find(key)!=map.end())
         {
              
              Node* temp = new Node();
              temp->key = key;
              temp->value = map[key]->value;
              
              pushFront(temp);
              popNode(map[key]);
              map[key] = temp;
              return map[key]->value;
         }
         return -1;
        
    }
    
    void put(int key, int value) 
    {
         if(current_size<=cap and map.find(key)!=map.end())
         {
              Node* node = new Node();
              node->key = key;
              node->value = value;
             
              pushFront(node);
               popNode(map[key]);
              map[key] = node;
          //     current_size++;
              
         }
         else if(current_size<cap and map.find(key)==map.end())
         {
              Node* node = new Node();
              node->key = key;
              node->value = value;
              pushFront(node);
              map[key] = node;
              current_size++;
              cout<<"ADDED "<<key<<endl;

         }
         else if(current_size>=cap)
         {
              map.erase(tail->key);
              
              Node* node = new Node();
              node->key = key;
              node->value = value;
              pushFront(node);
              popNode(tail);
              map[key] = node;
              cout<<"REMOVED AND ADDED"<<endl;
         }
         


         
    }

     
};


int main()
{
     LRUCache obj(2);
     cout<<obj.get(2)<<endl;
     obj.put(2,6);
     cout<<obj.get(1)<<endl;
     obj.put(1,5);
     obj.put(1,2);
     cout<<obj.get(1)<<endl;
     cout<<obj.get(2)<<endl;

     // obj.put(3,3);
     



     return 0;
}