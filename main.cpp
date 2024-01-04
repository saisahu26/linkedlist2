/*
  saikapish sahu
  linked list 2
  1/3/24
 */
#include <iostream>
#include <cstring>
#include "student.h"
#include "Node.h"

using namespace std;
Node *root = NULL;
void printNode(Node *temp);
Node *deleteNode(Node *current, int enterId) ;
Node *addNode(Node *current, Student *newNode) ;
bool nodeFound = false;
int main() {
  // recursion();
   char entry;
  int count = 0;
  // Node *root;
  Node *previous;
  while (true) { //while loop to continue to ask for what to do
    cout << " add ('a') or delete ('d') or print ('p') " << endl;
    cin >> entry;
    //creating the objects in meain
    float gpa;
    int id;
    string fname;
    string lname;
    if (entry == 'a') {
      cout << " Add student record " << endl;
      Student *st = new Student; //create new pointer to student

      cin >> gpa;
      cin >> id;
      cin >> fname;
      cin >> lname;
      float preGPA = ceilf(gpa * 100)/100; //cap the gpa to 2 dec. palces

      st->add(preGPA, id, fname, lname); //add this into the list
      root = addNode(root, st);//create a root
  }
    else if (entry == 'd') {
      cout << "enter student id delete" << endl;
      Node *temp = root; //create a temp to hold the root
      int enterId; //enter the id to be deleted
      cin >>  enterId ;
      root = deleteNode(temp, enterId); //call the function passing in the temp and the id
      if (nodeFound == false) { //if the node is deleted then make sure to continue, if wrong id is sent then prompt
	cout <<"id not found" << endl;
      }
      else {
	nodeFound = false;
      }
    }
    else if (entry == 'p') {

      Student *sTemp; //pointer to student class
      Node *temp = root; //pointer to node which is root
      printNode(temp); //call function
      }
    else {
      cout <<"invalid entry" << endl;
    }
      

 

    }

  return 0;
}


Node *addNode(Node *head, Student *st) {

  
  if (head == NULL) { //if there is no head
    Node *current = new Node(st); //return this to become the head
      return current;
   }

   else { 
   
   Student *sTemp;
   sTemp = head->getStudent(); //temp hold of the head
   int tempId;
   tempId = sTemp->getID(); //id of the head

   if (!(tempId < st->getID())) { //if the id is less than the hea dmove it before

       Node *current = new Node(st);
       current->setNext(head);
       return current;
     

   }

 
   head->setNext(addNode(head->getNext(),st)); //else move to the next node and do the same again till you find a value that is greater
    return head;
    }


}

Node *deleteNode(Node *current, int enterId) {


  if (current == NULL) { //if current is null return null because nothing is there

       return NULL;

   }
   else {

       Student *sTemp;
       sTemp = current->getStudent();
       int tempId;
       tempId = sTemp->getID();
       if (enterId == tempId) { //if your id matches one of the classes
    
	 Node *next = current->getNext(); //set the node to current
	 delete current;//delete the current
	 nodeFound = true; //set the node found to true
	 return deleteNode(next, enterId);  


       } else {


	 current->setNext(deleteNode(current->getNext(), enterId)); //else move on to the next node
            return current;


       }
   } 

  
}


  

  void printNode(Node *temp) {
    Student *sTemp; //create a temp student
    if (temp == NULL) {
      return;
    }
    else {
    
      sTemp = temp->getStudent();        //get the student                                                                                                                                                                     
      sTemp->print(); //call the print function and print
	
      return  printNode(temp->getNext());  //keep on printing the nodes
    }

  
}

