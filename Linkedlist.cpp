
 /* Done By Jawad Alkassim
        This Code Has No Memory Leak Tested With *Valgrind*
        Test OutPut:
    ==11966== HEAP SUMMARY:
    ==11966==     in use at exit: 0 bytes in 0 blocks
    ==11966==   total heap usage: 7 allocs, 7 frees, 74,824 bytes allocated
    ==11966==
    ==11966== All heap blocks were freed -- no leaks are possible
    ==11966==
    ==11966== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
*/

#include <assert.h>
#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;


// A linked list node
struct Node
{
    Node* next;    // structure should have at least one variable for data section and a pointer for the next node.
    int data;

};

class LinkedList // Create LinkedList Class  which will contain the functions to handle the nodes.
{
public: //Public Members
    int length;
    Node* head;
    Node* current;

    LinkedList(); //Constructor
    ~LinkedList(); // Destructor
    void AddAsHead(int data); //Declare New Function Called AddAsHead (add new node at the beginnig of linked list)
    void AddAsTail(int data);//Declare Add AS TailFunction (add node at the end of linked list)
    bool isEmpty(); //Declare IsEmpty Function
    void addSorted(int data);//Declare Add Sorted Elements
    void Reverse();//Declare Reverse Nodes Function
    int FindNode(int index);//Declare Find Node Function
    void pop();//Declare Pop Function (Print First Node then Delete it)
    void print();//Declare Print Function
};

LinkedList::LinkedList(){ //constructor
    this->length = 0;
    this->head = NULL;
    current= NULL;


}

LinkedList::~LinkedList(){ //delete all the allocated nodes in the destructor.
    Node* next = head;
    Node* cur = NULL;
    while (next != NULL) {
        cur = next;
        next = next->next;
        delete cur;
    }
    std::cout << "LIST DELETED";
}



bool LinkedList::isEmpty(){

    if (this->head == NULL) { // if head pointer point to NULL
        return 1; //then the list is Empty return 1
    }
    else  {
        return 0; // if not return 0 and the list is not empty
    }
}

void LinkedList::AddAsHead(int data){ //Add Node at The Begining of the Linked List
    Node* node = new Node(); //Create new Node
    node->data = data;   //set node data to equal entry data by user
    node->next = this->head; // set  node next Pointer to head
    this->head = node; // make head points to the new node
    this->length++; // increase the length of the list by 1

}

void LinkedList::AddAsTail(int data){

    Node *last = new Node;
    last->data = data;
    last->next = NULL;
    // if the linked list is empty then set head = last
    if (this->head == NULL) {
        this->head = last;
    }
    else { // if the linked list is not empty
        // creates a temp node and sets it to head
        Node *temp = head;
        // temp = this->head;
        // uses temp to find the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // appends the last node with last
        temp->next = last;
    }
    this->length++;



}

  void LinkedList::addSorted( int data ) {


     //  Before Adding new Data this Code checks if the LinkedList is Sorted or not
        //Node current will point to head

        Node *current = head, *index = NULL;
        int temp;

        if(head == NULL) {
            return;
        }
        else {

            while(current != NULL) {
                //Node index will point to node next to current
                index = current->next;

            while(index != NULL) {

                //If current node's data is greater than index's node data, swap the data between them
                    if(current->data > index->data) {
                        temp = current->data;
                        current->data = index->data;
                        index->data = temp;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }

        Node* temp1 = new Node;
        temp1->data = data;

        Node* temp2 = this->head;  //Initialize temp2 to head, and keep looping until we reach the end of the list
        Node** temp3 = &head;

        while(temp2 != NULL && temp2->data < temp1->data) //or until temp2's data is >= than temp1's data. In each iteration of the loop, advance both temp3 and temp2.
        {
            temp3 = &temp2->next;
            temp2 = temp2->next;
         }

            //The 'temp3' pointer points to where 'temp1' would need to go
            *temp3 = temp1;
            temp1->next = temp2;
            this->length++;

    }


    void LinkedList::Reverse(){

            if (head == NULL) //CHeck if the List If Empty
            {
                return;
            }
            Node* prev = NULL; //declare Three new pointers "prev , curr , next"
            Node* curr = head;
            Node* next = NULL;


            while (curr != NULL ){  // This Check if the List is not empty
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;

    }

int LinkedList::FindNode(int data) { //takes a linked list and an integer index and returns the data value stored in the node at that index position
    current = head; //sets current node to first node
    int currIndex = 1; //integer current index is 0 so starting at the beginning

    while (current != NULL) { //if there is something in current meaning if the list hasnt ended yet
        if (currIndex == data) { //if the current index number is equal to the number I put when setting parameter
            // return (current->data); //store the current value in the current node into its data
    return (current->data);

        }
        else {
        currIndex++; //increase current index by 1
        current = current->next; //set current node to the next node
        }
    }
    assert(0); //If it is not, FindNode() should assert() fail (or you could implement some other error case strategy).

}

void LinkedList::pop() { // This Funcyion Print First Node Data Then Delete it
    Node* top =head;  // Set top to head
   if(top==NULL) //if conditional
      cout<<"Stack Underflow"<<endl;
   else {
      cout<<"The popped element is "<< top->data <<endl;

    Node* tmp = top->next; // set top next pointer points to tmp
    head = tmp;     //set head to tmp
    delete top;     //freeing top pointer from memory by this Delete Command
    this->length--;

   }
}

void LinkedList::print(){ //Print Function
    Node* head = this->head;
    int i = 1;

    if (isEmpty() == 1) { //Checks the output of IsEmpty Function if it's 1

        cout<<"**This list is empty**"<<endl; //print this
    }
    else {

        cout<<"**This list is not empty**" << endl; // else the list not empty and IsEmpty Func returning 0

    while(head){ //keep looping and print all the list
        std::cout << i << ": " << head->data << std::endl;
        head = head->next;
        i++;
    }
    }

}
int main(int argc, char const *argv[])
{
    Node* head = NULL;  // Start with the empty list
    LinkedList* list = new LinkedList(); //create new list


 while (1) //While 1 for keep the program Running until you press 0
 {
     int x,data; //define data, x as integer

     cout<<"*****WELCOME To LinkedList Implementation Program In C++*****"<<endl //Outout
     <<"** Add First -----> Press 1"<<endl
     <<"** Add At The End -----> Press 2"<<endl
     <<"** Add Sorted -----> Press 3"<<endl
     <<"** Reverse List -----> Press 4"<<endl
     <<"** Find Node -----> Press 5"<<endl
     <<"** Print First Element and delete it - POP() -----> Press 6"<<endl
     <<"** To Quit -----> Press 0"<<endl;


    while(!(cin >> x)){ // Very important ----> Clearing the Buffer input to prevent program from entering infinite loop and causes undesired outputs
                        //  ex: by adding a string not an integer
            cin.clear();    //Clearing The Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discards the input buffer
            cout << "Invalid input.  Try again: "; }

    if (x==0)  //Pressing 0 Will break you out of the loop
            {
                break;
            }

    switch (x) // Switch Statment for Output
        {      //each case will contain a Function So the user can choose between them and call the needed func.

        case 1:
            cout<<"Enter Value:\n"<<endl;
            while(!(cin >> data)){ // Very important ----> Clearing the Buffer input to prevent program from entering infinite loop and causes undesired outputs
                        //  ex: by adding a string not an integer
            cin.clear();    //Clearing The Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discards the input buffer
            cout << "Invalid input.  Try again: "; }
            cout<<"\nOUTPUT:\n";
            list->AddAsHead(data);
            list->print();
            std::cout << "List Length: " << list->length << std::endl;
            cout<<"\n";
            break;

        case 2:
            cout<<"Enter Value:\n"<<endl;
            while(!(cin >> data)){ // Very important ----> Clearing the Buffer input to prevent program from entering infinite loop and causes undesired outputs
                        //  ex: by adding a string not an integer
            cin.clear(); //Clearing The Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discards the input buffer
            cout << "Invalid input.  Try again: "; }
            cout<<"\nOUTPUT:\n";
            list->AddAsTail(data);
            list->print();
            std::cout << "List Length: " << list->length << std::endl;
            cout<<"\n";
            break;

        case 3:
            cout<<"Enter Value:\n"<<endl;
            while(!(cin >> data)){ // Very important ----> Clearing the Buffer input to prevent program from entering infinite loop and causes undesired outputs
                        //  ex: by adding a string not an integer
            cin.clear(); //Clearing The Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discards the input buffer
            cout << "Invalid input.  Try again: "; }
            cout<<"\nOUTPUT:\n";
            list->addSorted(data);
            list->print();
            std::cout << "List Length: " << list->length << std::endl;
            cout<<"\n";
            break;

        case 4:
            cout<<"\nOUTPUT:\n"; //Call Reverse Function by pressing 6
            list->Reverse();
            list->print();
            std::cout << "List Length: " << list->length << std::endl;
            cout<<"\n";
            break;


        case 5:
            cout<<"Enter Value:\n"<<endl;
            while(!(cin >> data)){ // Very important ----> Clearing the Buffer input to prevent program from entering infinite loop also causes undesired outputs
                        //  ex: by adding a string not an integer
            cin.clear(); //Clearing The Buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // discards the input buffer
            cout << "Invalid input.  Try again: "; }
            cout<<"\nOUTPUT:\n";
            std::cout<<"Node"<<" "<<data<<" "<<"Is Found in The List With Data :"<<" "<<list->FindNode(data)<<endl;
            list->print();
            cout<<"\n";
            break;


        case 6:
            cout<<"\nOUTPUT:\n";
            list->pop();
            list->print();
            std::cout << "List Length: " << list->length << std::endl;
            cout<<"\n";
            break;

        }


 }

    delete list; //freeing list from memory
    cout<<"\n";
    return 0;
}
