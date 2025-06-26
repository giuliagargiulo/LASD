
#ifndef MYTEST_CPP
#define MYTEST_CPP

/* ************************************************************************** */

/* ************************************************************************** */

#include <iostream>
#include <random>

using namespace std;
#define dim 10

#include "test.hpp"
default_random_engine gen(random_device{}());
uniform_int_distribution<int> RandomNumber(0, 100);
uniform_int_distribution<int> RandomChar(32, 126);
uniform_int_distribution<int> RandomChar2(128, 255);
uniform_real_distribution<double> RandomDouble(0,100);
/* ************************************************************************** */

void mytest(){
  int choose;
  bool exit = false;

  cout << " ~ My Test ~ " <<endl<<endl;
  while(!exit){
    cout<< "Scegliere il test da eseguire: " << endl<< "1) Eseguire Test Esercizio 1 "<< endl<< "2) Eseguire Test Esercizio 2"<< endl<< "3) Eseguire Test Esercizio 3"<<endl<< "4) Esci"<<endl << "Inserire la scelta: ";
    cin>>choose;
    cout<<endl;
    switch(choose){
      case 1: mytest1(); break;
      case 2: mytest2(); break;
      case 3: mytest3(); break;
      case 4: exit = true; break;
      default:
        std::cout << "Scelta non valida" << std::endl; break;
    }
    cout<<endl<<endl;
  }
  cout<<"Goodbye!"<<endl;
}

// -------------- TEST COSTRUTTORI --------------

bool TestCostruttori(){

  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;
  cout << "BEGIN OF CONSTRUCTOR TEST" << endl;

  cout<< "("<< ++numTest<< ")"<< " Test Copy constructor Vector<int>: ";
  lasd::Vector<int> vec(dim);
  for(ulong i=0; i<vec.Size(); i++) vec[i] = RandomNumber(gen);
  lasd::Vector<int> vec2(vec);
  
  if(vec == vec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }
 
  cout<< "("<< ++numTest<< ")"<< " Test Move constructor Vector<int>: ";
  lasd::Vector<int> vec3(std::move(vec2));

 if(vec2.Empty())
   cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }
  
  cout<< "("<< ++numTest<< ")"<< " Test Copy constructor List<int>: ";
  lasd::List<int> list;
  for(ulong i=0; i<dim; i++) list.InsertAtBack(RandomNumber(gen));
  lasd::List<int> list2(list);

  if (list == list2)
    cout << "Correct!" << endl;
  else{ 
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<  "("<< ++numTest<< ")"<< " Test Move constructor List<int>: ";
  lasd::List<int> list3(std::move(list2));

  if (list2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<  "("<< ++numTest<< ")"<< " Test copy constructor QueueVec<int>: ";
  lasd::QueueVec<int> queueVec;
  for(ulong i=0; i<dim; i++) queueVec.Enqueue(RandomNumber(gen));
  lasd::QueueVec<int> queueVec2(queueVec);

  if(queueVec == queueVec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test Move constructor QueueVec<int>: ";
  lasd::QueueVec<int> queueVec3(std::move(queueVec2));

  if(queueVec2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }


  cout<<  "("<< ++numTest<< ")"<< " Test Copy constructor StackVec<int>: ";
  lasd::StackVec<int> stackVec;
  for(ulong i=0; i<stackVec.Size(); i++) stackVec.Push(RandomNumber(gen));
  lasd::StackVec<int> stackVec2(stackVec);

  if(stackVec == stackVec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor StackVec<int>: ";
  lasd::StackVec<int> stackVec3(std::move(stackVec2));

  if(stackVec2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "("<< ++numTest<< ")"<<  " Test copy constructor QueueLst<int>";
  lasd::QueueLst<int> queueLst;
  for(ulong i=0; i<dim; i++) queueLst.Enqueue(RandomNumber(gen));
  lasd::QueueLst<int> queueLst2(queueLst);
  if(queueLst == queueLst2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout <<  "("<< ++numTest<< ")"<< " Test move constructor QueueLst<int>";
  lasd::QueueLst<int> queueLst3(std::move(queueLst2));

  if(queueLst2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "("<< ++numTest<< ")"<<  " Test copy constructor StackLst<int>";
  lasd::StackLst<int> stackLst;
  for(ulong i=0; i<dim; i++) stackLst.Push(RandomNumber(gen));
  lasd::StackLst<int> stackLst2(stackLst);

  if(stackLst == stackLst2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "("<< ++numTest<< ")"<<  " Test move constructor StackLst<int>";
  lasd::StackLst<int> stackLst3(std::move(stackLst2));

  if(stackLst2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }


  cout<< "("<< ++numTest<< ")"<< " Test copy constructor List<int> from Vector<int>: ";
  lasd::Vector<int> vec4(dim);
  for(ulong i=0; i<dim; i++) vec4[i] = RandomNumber(gen);
  lasd::List<int> list4(vec4);
 
  for(ulong i=0; i<list.Size(); i++){
    if(vec4[i] != list4[i]){
      cout << "Error!" << endl; errors++; TestPassed &= false;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<< " Test move constructor List<int> from Vector<int>: ";
  lasd::List<int> vec5(vec4);
  lasd::List<int> list5(std::move(vec4));

  for(ulong i=0; i<dim; i++){
    if(vec5[i] != list5[i]){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<< " Test copy constructor Vector<int> from List<int>: ";
  lasd::List<int> list6;
  for(ulong i=0; i<dim; i++) list6.InsertAtBack(RandomNumber(gen));
  lasd::Vector<int> vec6(list6);

  for(ulong i=0; i<dim; i++){
    if(vec6[i] != list6[i]){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<< " Test move constructor Vector<int> from List<int>: ";
  lasd::List<int> list7(list6);
  lasd::Vector<int> vec7(std::move(list6));

  for(ulong i=0; i<dim; i++){
    if(vec7[i] != list7[i]){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor StackLst<int> from Vector<int>: ";
  lasd::Vector<int> vec8(dim);
  for(ulong i=0; i<vec.Size(); i++) vec8[i] = RandomNumber(gen);
  lasd::StackLst<int> stackLst4(vec8);

  for(ulong i=0; i<dim; i++){
    if(vec8[i] != stackLst4.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  } 
  
  cout<< "("<< ++numTest<< ")"<<  " Test move constructor StackLst<int> from Vector<int>: ";
  lasd::Vector<int> vec9(vec8);
  lasd::StackLst<int> stackLst5(std::move(vec8));

  
  for(ulong i=0; i<dim; i++){
    if(vec9[i] != stackLst5.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor StackVec<int> from Vector<int>: ";
  lasd::Vector<int> vec14(dim);
  for(ulong i=0; i<dim; i++) vec14[i] = RandomNumber(gen);
  lasd::StackVec<int> stackVec4(vec14);

  for(long i=dim-1; i >= 0; i--){
   if(vec14[i] != stackVec4.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
   if(i == 0)
     cout << "Correct!" << endl;
  }


  cout<< "("<< ++numTest<< ")"<<  " Test move constructor StackVec<int> from Vector<int>: ";
  lasd::Vector<int> vec15(vec14);
  lasd::StackVec<int> stackVec5(std::move(vec14));
 
  for(long i=dim-1; i>=0; i--){
    if(vec15[i] != stackVec5.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == 0)
      cout << "Correct!" << endl;
    
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor QueueLst<int> from Vector<int>: ";
  lasd::Vector<int> vec10(dim);
  for(ulong i=0; i<dim; i++) vec10[i] = RandomNumber(gen);
  lasd::QueueLst<int> queueLst4(vec10);

  for(ulong i=0; i<dim; i++){
    if(vec10[i] != queueLst4.HeadNDequeue()){ 
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor QueueLst<int> from Vector<int>: ";
  lasd::Vector<int> vec11(vec10);
  lasd::QueueLst<int> queueLst5(std::move(vec10));

  for(ulong i=0; i<dim; i++){
    if(vec11[i] != queueLst5.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }
  
  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor QueueVec<int> from Vector<int>: ";
  lasd::Vector<int> vec12(dim);
  for(ulong i=0; i<vec.Size(); i++) vec12[i] = RandomNumber(gen);
  lasd::QueueVec<int> queueVec4(vec12);

  for(ulong i=0; i<dim; i++){
    if(vec12[i] != queueVec4.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor QueueVec<int> from Vector<int>: ";
  lasd::Vector<int> vec13(vec12);
  lasd::QueueVec<int> queueVec5(std::move(vec12));

  for(ulong i=0; i<dim; i++){
    if(vec13[i] != queueVec5.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor StackLst<int> from List<int>: ";
  lasd::List<int> list8;
  for(ulong i=0; i<dim; i++) list8.InsertAtBack(RandomNumber(gen));
  lasd::StackLst<int> stackLst6(list8);

  for(ulong i=0; i<dim; i++){
    if(list8[i] != stackLst6.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor StackLst<int> from List<int>: ";
  lasd::List<int> list9(list8);
  lasd::StackLst<int> stackLst7(std::move(list8));
  
  for(ulong i=0; i<dim; i++){
    if(list9[i] != stackLst7.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor StackVec<int> from List<int>: ";
  lasd::List<int> list10;
  for(ulong i=0; i<dim; i++) list10.InsertAtBack(RandomNumber(gen));
  lasd::StackVec<int> stackVec6(list10);
  
  for(long i=dim-1; i>=0; i--){
    if(list10[i] != stackVec6.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == 0)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor StackVec<int> from List<int>: ";
  lasd::List<int> list11(list10);
  lasd::StackVec<int> stackVec7(std::move(list10));

  for(long i=dim-1; i>=0; i--){
    if(list11[i] != stackVec7.TopNPop()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == 0)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor QueueLst<int> from List<int>: ";
  lasd::List<int> list12;
  for(ulong i=0; i<dim; i++) list12.InsertAtBack(RandomNumber(gen));
  lasd::QueueLst<int> queueLst6(list12);

  for(ulong i=0; i<dim; i++){
    if(list12[i] != queueLst6.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor QueueLst<int> from List<int>: ";
  lasd::List<int> list13(list12);
  lasd::QueueLst<int> queueLst7(std::move(list12));

  for(ulong i=0; i<dim; i++){
    if(list13[i] != queueLst7.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test copy constructor QueueVec<int> from List<int>: ";
  lasd::List<int> list14;
  for(ulong i=0; i<dim; i++) list14.InsertAtBack(RandomNumber(gen));
  lasd::QueueVec<int> queueVec6(list14);
  
  for(ulong i=0; i<dim; i++){
    if(list14[i] != queueVec6.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

  cout<< "("<< ++numTest<< ")"<<  " Test move constructor QueueVec<int> from List<int>: ";
  lasd::List<int> list15(list14);
  lasd::QueueVec<int> queueVec7(std::move(list14));

  for(ulong i=0; i<dim; i++){
    if(list15[i] != queueVec7.HeadNDequeue()){
      cout << "Error!" << endl; errors++; TestPassed &= false; break;
    }
    if(i == dim-1)
      cout << "Correct!" << endl;
  }

// forse devo mettere clear in tutti i move constructor????
cout << "END OF CONSTRUCTOR TEST: ("<< errors << "/" << numTest  << ") " ;
return TestPassed;
}

// -------------- TEST ASSEGNAMENTI --------------

// Copy assignment Vector
bool TestAssignment(){

  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;
  cout << "BEGIN OF ASSIGNMENT TEST" << endl;
  
  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from Vector<int> to Vector<int>: ";
  lasd::Vector<int> vec(dim);
  for(ulong i=0; i<vec.Size(); i++) vec[i]=RandomNumber(gen);    
  lasd::Vector<int> vec2; 
  vec2 = vec; 

  if(vec == vec2) 
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "("<< ++numTest<< ")"<< " Test Move assignment from Vector<int> to Vector<int>: ";
  lasd::Vector<int> vec3;
  vec3 = std::move(vec2);
  
  if((vec3==vec) && (vec2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from List<int> to List<int>: ";
  lasd::List<int> list;
  for(ulong i=0; i<dim; i++) list.InsertAtBack(RandomNumber(gen));
  lasd::List<int> list2;
  list2 = list;

  if(list == list2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Move assignment from List<int> to List<int>: ";
  lasd::List<int> list3;
  list3 = std::move(list2);

  if((list3==list) && (list2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from QueueVec<int> to QueueVec<int>: ";
  lasd::QueueVec<int> queueVec;
  for(ulong i=0; i<dim; i++) queueVec.Enqueue(RandomNumber(gen));
  lasd::QueueVec<int> queueVec2;
  queueVec2 = queueVec;

  if(queueVec == queueVec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Move assignment from QueueVec<int> to QueueVec<int>: ";
  lasd::QueueVec<int> queueVec3;
  queueVec3 = std::move(queueVec2);

  if((queueVec3==queueVec) && (queueVec2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }


  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from QueueLst<int> to QueueLst<int>: ";
  lasd::QueueLst<int> queueLst;
  for(ulong i=0; i<dim; i++) queueLst.Enqueue(RandomNumber(gen));
  lasd::QueueLst<int> queueLst2;
  queueLst2 = queueLst;

  if(queueLst == queueLst2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Move assignment from QueueLst<int> to QueueLst<int>: ";
  lasd::QueueLst<int> queueLst3;
  queueLst3 = std::move(queueLst2);

  if((queueLst3==queueLst) && (queueLst2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from StackVec<int> to StackVec<int>: ";
  lasd::StackVec<int> stackVec;
  for(ulong i=0; i<dim; i++) stackVec.Push(RandomNumber(gen));
  lasd::StackVec<int> stackVec2;
  stackVec2 = stackVec;
  
  if(stackVec == stackVec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Move assignment from StackVec<int> to StackVec<int>: ";
  lasd::StackVec<int> stackVec3;
  stackVec3 = std::move(stackVec2);

  if((stackVec3==stackVec) && (stackVec2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Copy assignment from StackLst<int> to StackLst<int>: ";
  lasd::StackLst<int> stackLst;
  for(ulong i=0; i<dim; i++) stackLst.Push(RandomNumber(gen));
  lasd::StackLst<int> stackLst2;
  stackLst2 = stackLst;

  if(stackLst == stackLst2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<< "("<< ++numTest<< ")"<< " Test Move assignment from StackLst<int> to StackLst<int>: ";
  lasd::StackLst<int> stackLst3;
  stackLst3 = std::move(stackLst2);

  if((stackLst3==stackLst) && (stackLst2.Empty()))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "END OF ASSIGNMENT TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}


bool ListFunctionsTest(){

  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout << "BEGIN OF LIST FUNCTIONS TEST" << endl;

  cout << "("<< ++numTest<< ")"<<  " Test Clear(): ";
  lasd::List<int> list;
  for(ulong i=0; i<dim; i++) list.InsertAtBack(RandomNumber(gen));
  list.Clear();
  if(list.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Insert(): ";
  lasd::List<int> list1;
  for(ulong i=0; i<dim-3; i++) list1.Insert(i);
  list1.Insert(5);
  list1.Insert(6);
  list1.Insert(66);
  for(ulong i = 0; i<list1.Size(); i++) cout<< list1[i] << " ";

  if(list1.Size() == dim-2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Exists(): ";
  if(list1.Exists(5) && list1.Exists(6) && list1.Exists(66))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Exists(): ";
  if(list1.Exists(0) && list1.Exists(1) && list1.Exists(2))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Exists(): ";
  if(!list1.Exists(10) && !list1.Exists(55))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  
  cout << "("<< ++numTest<< ")"<<  " Test Front(): ";
  lasd::List<int> list2;
  for(ulong i=0; i<dim; i++) list2.InsertAtBack(RandomNumber(gen));
  if(list2.Front() == list2[0])
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Back(): ";
  if(list2.Back() == list2[dim-1])
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromBack(): ";
  lasd::List<int> list3;  
  for(ulong i=0; i<dim; i++) list3.InsertAtBack(i);
  cout<< "List Back = "<< list3.Back();
  list3.RemoveFromBack();
  if(list3.Size() == dim-1 && list3.Back() == list3[dim-2])
    cout << " Correct!" << endl;
  else{
    cout << " Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromBack(): ";
  lasd::List<int> list4;
  for(ulong i=0; i<2; i++) list4.InsertAtBack(i);
  cout<< "List Back = "<< list4.Back();
  list4.RemoveFromBack();

  if(list4.Size() == 1 && list4.Back() == 0)
    cout << " Correct!" << endl;
  else{
    cout << " Error!" << endl; TestPassed &= false; errors++;
  }

 cout << "("<< ++numTest<< ")"<<  " Test RemoveFromBack(): ";
  list4.RemoveFromBack();
  if(list4.Empty())
    cout << "Removed element 0 from back, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromFront(): ";
  lasd::List<int> list5;
  for(ulong i=0; i<dim; i++) list5.InsertAtBack(i);
  cout<< "List Front = "<< list5.Front();
  list5.RemoveFromFront();

  if((list5.Size()== dim-1) && (list5.Front() == 1))
    cout << " Removed element 0 from front, Correct!" << endl;
  else{
    cout << " Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromFront(): ";
  lasd::List<int> list6;
  for(ulong i=0; i<2; i++) list6.InsertAtBack(i);
  cout<< "List Front = "<< list6.Front();
  list6.RemoveFromFront();

  if((list6.Size()== 1) && (list6.Front() == 1))
    cout << " Removed element 0 from front, Correct!" << endl;
  else{
    cout << " Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromFront(): ";
  if((list6.Size()== 1) && (list6.Front() == 1))
    cout << " Removed element 0 from front, Correct!" << endl;
  else{
   cout << " Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test RemoveFromFront(): ";
  list6.RemoveFromFront();
  if(list6.Empty())
    cout << "Removed element 1 from front, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  lasd::List<int> list7;
  for(ulong i=0; i<dim; i++) list7.InsertAtBack(i);
  list7.Remove(0);
  if(list7.Size() == dim-1 && list7.Front() == 1)
    cout << "Removed element 0, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list7.Remove(9);
  if(list7.Size() == dim-2 && list7.Back() == 8)
    cout << "Removed element 9, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list7.Remove(6);
  if(list7.Size() == dim-3 && list7[5] == 7)
    cout << "Removed element 6, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list7.Remove(8);
  if(list7.Size() == dim-4 && list7.Back() == 7)
    cout << "Removed element 8, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list7.Remove(7);
  if(list7.Size() == dim-5 && list7.Back() == 5)
    cout << "Removed element 7, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  bool test = list7.Remove(6);
  if(list7.Size() == dim-5 && test == false)
    cout << "Element 6 not in list , Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  test = list7.Remove(0);
  if(list7.Size() == dim-5 && test == false)
    cout << "Element 0 not in list , Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  for(uint i = 0; i< list7.Size(); i++) cout<< list7[i] << " ";
  cout<< endl;

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  lasd::List<int> list8;
  list8.InsertAtBack(0);
  list8.Remove(0);
  if(list8.Empty())
    cout << "Removed element 0, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  lasd::List<int> list9;
  list9.InsertAtBack(1);
  list9.InsertAtBack(2);

  list9.Remove(1);
  if(list9.Size() == 1 && list9.Front() == 2)
    cout << "Removed element 1, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list9.Remove(2);
  if(list9.Empty())
    cout << "Removed element 2, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  lasd::List<int> list10;
  list10.Insert(2);
  list10.Insert(1);
  list10.Insert(0);

  list10.Remove(1);
  if(list10.Size() == 2 && list10[0] == 2)
    cout << "Removed element 1, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "("<< ++numTest<< ")"<<  " Test Remove(): ";
  list10.Remove(0);
  if(list10.Size() == 1 && list10.Front() == 2)
    cout << "Removed element 0, Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  

  cout << "END OF LIST FUNCTIONS TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}


bool QueueVecFunctionsTest(){

  cout<< "BEGIN OF QueueVec FUNCTIONS TEST" << endl;
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout<< "("<< ++numTest << ")"<< " Test Clear(): ";
  lasd::QueueVec<int> queueVec;
  for(ulong i=0; i<dim; i++) queueVec.Enqueue(RandomNumber(gen));
  queueVec.Clear();
  if(queueVec.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "END OF QueueVec FUNCTIONS TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}

bool StackVecFunctionsTest(){

  cout<< "BEGIN OF StackVec FUNCTIONS TEST" << endl;
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout<< "("<< ++numTest << ")"<< " Test Clear(): ";
  lasd::StackVec<int> stackVec;
  for(ulong i=0; i<dim; i++) stackVec.Push(RandomNumber(gen));
  stackVec.Clear();

  if(stackVec.Size() == 0)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<< "("<< ++numTest << ")"<< " Test Push(): ";
  lasd::StackVec<int> stackVec1;
  for(uint i = 0; i< 15; i++){
    stackVec1.Push(i);
    cout << stackVec1.Top()<<" ";
  }
  cout<<"Correct!"<<endl;

  cout<< "("<< ++numTest << ")"<< " Test TopNPop(): ";
  for(uint i = 0; i< 15; i++){
    cout << stackVec1.TopNPop()<<" ";
  }
  cout<<"Correct!"<<endl;
  
  cout << "END OF StackVec FUNCTIONS TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}

/* ************************************************************************** */

void mytest1() {
  cout<< " ~ BEGIN MYTEST 1 ~ " << endl<<endl;
  cout<< (TestCostruttori() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<< (TestAssignment() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<< (ListFunctionsTest() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<< (QueueVecFunctionsTest() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<< (StackVecFunctionsTest() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<< " ~ END MYTEST 1 ~ " << endl;
}

/* ************************************************************************** */

bool TestBinaryTreeLink(){

  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;
  cout << "BEGIN OF BINARY TREE LINK TEST" << endl;

  cout<<"("<< ++numTest<< ")"<< " Test Copy constructor Empty BinaryTreeLnk<int>: ";
  lasd::BinaryTreeLnk<int> btlnk12;
  lasd::BinaryTreeLnk<int> btlnk13(btlnk12);

  if (btlnk12 == btlnk13)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move constructor Empty BinaryTreeLnk<int>: ";
  lasd::BinaryTreeLnk<int> btlnk14(std::move(btlnk12));

  if(btlnk12.Empty() && btlnk13 == btlnk14)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy constructor BinaryTreeLnk<int>: ";
  lasd::BinaryTreeLnk<int> btlnk;
  lasd::Vector<int> vec(dim);
  for(ulong i=0; i<dim; i++) vec[i] = RandomNumber(gen);
  btlnk = vec;
  lasd::BinaryTreeLnk<int> btlnk2(btlnk);

  if (btlnk == btlnk2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move constructor BinaryTreeLnk<int>: ";
  lasd::BinaryTreeLnk<int> btlnk3(std::move(btlnk2));

  if(btlnk == btlnk3 && btlnk2.Empty()){
    cout << "Correct!" << endl;
  }
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy assingment BinaryTreeLnk<int>: ";
  btlnk3.Clear();
  btlnk3 = btlnk;

  if(btlnk == btlnk3)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move assingment BinaryTreeLnk<int>: ";
  btlnk3.Clear();
  btlnk2 = btlnk;
  btlnk3 = std::move(btlnk);
  if(btlnk2 == btlnk3 && btlnk.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Clear() BinaryTreeLnk<int>: ";
  btlnk.Clear();
  btlnk2.Clear();
  if(btlnk.Empty() && btlnk2.Empty() && btlnk == btlnk2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  
  
  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeLnk<int> obtained from List<int>: ";
  lasd::List<int> list;
  for(ulong i=0; i<dim; i++) list.InsertAtBack(RandomNumber(gen));
  lasd::BinaryTreeLnk<int> btlnk4(list);
  lasd:: BinaryTreeLnk<int> btlnk5(std::move(list));
  if(btlnk4 == btlnk5 && !btlnk4.Empty() && !btlnk5.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeLnk<int> from Vector<int>: ";
  lasd::Vector<int> vec1(dim);
  for(ulong i=0; i<dim; i++) vec1[i] = RandomNumber(gen);
  lasd::BinaryTreeLnk<int> btlnk6(vec1);
  lasd:: BinaryTreeLnk<int> btlnk7(std::move(vec1));

  if(btlnk6 == btlnk7 && !btlnk6.Empty() && !btlnk7.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  
  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeLnk<int> from BinaryTreeVec<int>: ";
  lasd::BinaryTreeVec<int> btvec(vec1);
  lasd::BinaryTreeLnk<int> btlnk10(btvec);
  
  lasd::BTPreOrderIterator<int> i(btlnk10);
  lasd::BTPreOrderIterator<int> j(btvec);
  while(!i.Terminated()){
      if((*i) != (*j)){
        cout << "Error!" << endl; errors++; TestPassed &= false;
      }
      ++i; ++j;
  }
  if(errors == 0)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }
  
  //Root()
  cout<<"("<< ++numTest<< ")"<< " Test Root() BinaryTreeLnk<int>: ";
  lasd::List<int> list2;
  lasd::BinaryTreeLnk<int> btlnk8;
  btlnk8 = list2;
  try{
    btlnk8.Root();
  } catch (const std::length_error & exp) {
    cout<< exp.what() << " ,Correct!" <<endl; 
  } catch (const std::exception & exp) {
    cout<< exp.what() << "Wrong exeption called, Error!" <<endl; 
    TestPassed &= false; errors++;
  }


  cout<<"("<< ++numTest<< ")"<< " Test Root() BinaryTreeLnk<int>: ";
  for(ulong i=0; i<dim; i++) list2.InsertAtBack(i);
  btlnk8 = list2;

  if(btlnk8.Root().Element() == 0)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  //Clear()
  cout<<"("<< ++numTest<< ")"<< " Test Clear() BinaryTreeLnk<int>: ";
  btlnk8.Clear();
  lasd::BinaryTreeLnk<int> btlnk9;

  if(btlnk8 == btlnk9 && btlnk8.Empty()){
    try{
      btlnk8.Root();
    } catch (const std::length_error & exp) {
      cout<< exp.what() << " ,Correct!"<< endl; 
    } catch (const std::exception & exp) {
      cout<< exp.what() << "Wrong exeption called, Error!"<<endl; 
      TestPassed &= false; errors++;
    }
  }
  else{
      cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "END OF BINARY TREE LINK TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}

bool TestBinaryTreeVec(){

  cout<< "BEGIN OF BINARY TREE VEC TEST" << endl;
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout<<(++numTest)<< " Test Copy constructor Empty BinaryTreeVec<int>: ";
  lasd::BinaryTreeVec<int> btvec4;
  lasd::BinaryTreeVec<int> btvec5(btvec4);

  if(btvec4 == btvec5)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move constructor Empty BinaryTreeVec<int>: ";
  lasd::BinaryTreeVec<int> btvec6(std::move(btvec5));
  
  if(btvec4 == btvec6 && btvec5.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }


  cout<<"("<< ++numTest<< ")"<< " Test Copy constructor BinaryTreeVec<int>: ";
  lasd::Vector<int> vec(dim);
  for(ulong i=0; i<dim; i++) vec[i] = RandomNumber(gen);
  lasd::BinaryTreeVec<int> btvec(vec);
  lasd::BinaryTreeVec<int> btvec2(btvec);

  if (btvec == btvec2 && !btvec.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move constructor BinaryTreeVec<int>: ";
  lasd::BinaryTreeVec<int> btvec3(std::move(btvec2));

  if(btvec == btvec3 && btvec2.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy assingment BinaryTreeVec<int>: ";
  btvec3.Clear();
  btvec3 = btvec;

  if(btvec == btvec3)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move assingment BinaryTreeVec<int>: ";
  btvec3.Clear(); btvec2.Clear();
  btvec2 = btvec;
  btvec3 = std::move(btvec);
  if(btvec2 == btvec3 && btvec.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Clear() BinaryTreeVec<int>: ";
  btvec.Clear();
  btvec2.Clear();
  if(btvec.Empty() && btvec2.Empty() && btvec == btvec2)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeVec<int> from List<int>: ";
  lasd::List<int> list;
  for(ulong i=0; i<dim; i++) list.InsertAtBack(RandomNumber(gen));
  lasd::BinaryTreeVec<int> btvec7(list);
  lasd:: BinaryTreeVec<int> btvec8(std::move(list));
  if(btvec7 == btvec8 && !btvec7.Empty() && !btvec8.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeVec<int> from Vector<int>: ";
  lasd::Vector<int> vec1(dim);
  for(ulong i=0; i<dim; i++) vec1[i] = RandomNumber(gen);
  lasd::BinaryTreeVec<int> btvec9(vec1);
  lasd:: BinaryTreeVec<int> btvec10(std::move(vec1));

  if(btvec9 == btvec10 && !btvec9.Empty() && !btvec10.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BinaryTreeVec<int> from BinaryTreeLnk<int>: ";
  lasd::BinaryTreeLnk<int> btlnk;
  lasd::BinaryTreeVec<int> btvec11(btlnk);

  lasd::BTPreOrderIterator<int> i(btvec11);
  lasd::BTPreOrderIterator<int> j(btlnk);
  while(!i.Terminated()){
      if((*i) != (*j)){
        cout << "Error!" << endl; errors++; TestPassed &= false;
      }
      ++i; ++j;
  }
  if(errors == 0)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  //Root()
  cout<<"("<< ++numTest<< ")"<< " Test Root() BinaryTreeVec<int>: ";
  lasd::List<int> list2;
  lasd::BinaryTreeLnk<int> btvec13;
  btvec13 = list2;
  try{
    btvec13.Root();
  } catch (const std::length_error & exp){
    cout<< exp.what() << ", Correct! "<< endl; 
  } catch (const std::exception & exp) {
    cout<< exp.what()<< "Wrong exception called: Error!"<<endl; 
    TestPassed &= false;    
  }

  //Root()
  cout<<"("<< ++numTest<< ")"<< " Test Root() BinaryTreeVec<int>: ";
  lasd::List<int> list3;
  for(ulong i=0; i<dim; i++) list3.InsertAtBack(i);
  lasd::BinaryTreeVec<int> btvec12;
  btvec12 = list3;

  if(btvec12.Root().Element() == 0)
    cout << "Root is " << btvec12.Root().Element() << ", Correct!" << endl;
  else{
    cout << "Error!" << endl; errors++; TestPassed &= false;
  }

  cout << "END OF BINARY TREE VEC TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;

}

bool TestBST(){

  cout<< "BEGIN OF BST<int> TEST : "<< endl;
  bool TestPassed = true;
  ulong errors = 0;
  ulong numTest = 0;
  
  lasd::List<int> list;
  list.InsertAtBack(5);
  list.InsertAtBack(4);
  list.InsertAtBack(2);
  list.InsertAtBack(3);
  list.InsertAtBack(1);
  list.InsertAtBack(7);
  list.InsertAtBack(8);
  list.InsertAtBack(9);
  list.InsertAtBack(6);

  cout<<"("<< ++numTest<< ")"<< " Test Root(): ";
  lasd::BST<int> bst(list);
  
  if(bst.Root().Element() == 5)
    cout<<"Root is "<< bst.Root().Element()<<  ", Correct!"<< endl;
  else
    cout<<"Error!"<< endl;
  
  cout<<"("<< ++numTest<< ")"<< " Test LeftChild of 5 is: ";
  
  if(bst.Root().left->Element() == 4)
    cout<< bst.Root().left->Element()<< ", Correct!"<<endl;
  else
    cout<< "Error!"<<endl;

  cout<<"("<< ++numTest<< ")"<< " Test RightChild of 5 is: ";
  
  if(bst.Root().right->Element() == 7)
    cout<<bst.Root().right->Element()<< ", Correct!"<<endl;
  else
    cout<< "Error!"<<endl;


  cout<<"("<< ++numTest<< ")"<< " Test RightChild of 7 is: ";
  
  if(bst.Root().right->right->Element() == 8)
    cout<< bst.Root().right->right->Element()<< ", Correct!"<<endl;
  else
    cout<< "Error!"<<endl;

  cout<<"("<< ++numTest<< ")"<< " Test LeftChild of 7 is: ";
  
  if(bst.Root().right->left->Element() == 6)
    cout<< bst.Root().right->left->Element()<<", Correct!"<<endl;
  else
    cout<< "Error!"<<endl;
  

  cout<<"("<< ++numTest<< ")"<< " Test Copy Costructor BST<int>: ";
  
  lasd::BST<int> bst2(bst);
  if(bst == bst2)
    cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move Costructor BST<int>: ";
  lasd::BST<int> bst3(std::move(bst2));

  if(bst == bst3 && bst2.Empty())
    cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  lasd::Vector<int> vec(dim-1);
  for(ulong i = 1; i<= vec.Size(); i++) vec[i-1] = i;
  lasd::BST<int> bst4(vec);
  
  cout<<"("<< ++numTest<< ")"<< " Test operator== BST<int> with different structures : ";
  if(bst4 == bst)
    cout<<"The two BST<int> are equal, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BST<int> obtained from a Vector<int>: ";
  lasd::BST<int> bst5(std::move(vec));
  if(bst4 == bst5 && !bst4.Empty() && !bst5.Empty())
     cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BST<int> obtained from a List<int>: ";
  lasd::List<int> list2;
  list2.InsertAtBack(5);
  list2.InsertAtBack(4);
  list2.InsertAtBack(2);
  list2.InsertAtBack(3);
  list2.InsertAtBack(1);
  list2.InsertAtBack(7);
  list2.InsertAtBack(8);
  list2.InsertAtBack(9);
  list2.InsertAtBack(6);

  lasd::BinaryTreeLnk<int> btlnk(list2);
  lasd::BinaryTreeVec<int> btvec(list2);

  lasd::BST<int> bst6(list2);
  lasd::BST<int> bst7(std::move(list2));
  if(bst6 == bst7 && !bst6.Empty() && !bst7.Empty())
     cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test BST<int> obtained from a BinaryTreeLnk<int> ";
  lasd::BST<int> bst8(btlnk);
  lasd::BST<int>bst9(std::move(btlnk));
  if(bst8 == bst9)
     cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

cout<<"("<< ++numTest<< ")"<< " Test BST<int> obtained from a BinaryTreeVec<int> ";
lasd::BST<int> bst10(btvec);
lasd::BST<int>bst11(std::move(btvec));
  if(bst10 == bst11)
     cout << "Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Min() BST<int>: ";
  if(bst.Min() == 1)
    cout <<"Min of the BST is "<< bst.Min() << ", Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test RemoveMin() BST<int>: ";
  bst.RemoveMin();
  if(bst.Size() == 8 && bst.Min()!= 1)
    cout << "Min element = 1 has been removed, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test MinNRemove() BST<int>: ";
  if(bst.MinNRemove() == 2)
    cout << "Min element = 2 has been removed, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  lasd::List<int> list3; 
  list3.InsertAtBack(1);
  list3.InsertAtBack(2);
  lasd::BST<int> bst12(list3);

  cout<<"("<< ++numTest<< ")"<< " Test MinNRemove() BST<int>: ";

  if(bst12.MinNRemove() == 1){
    if(bst12.Root().Element() == 2)
      cout << "Min element = 1 has been removed, Correct!"<<endl;
  }
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test MinNRemove() BST<int>: ";

  if(bst12.MinNRemove() == 2){
    if(bst12.Empty())
       cout << "Min element = 2 has been removed, Correct!"<<endl;
  }
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  lasd::List<int> list4; 
  list4.InsertAtBack(2);
  list4.InsertAtBack(1);
  lasd::BST<int> bst13(list4);

   cout<<"("<< ++numTest<< ")"<< " Test MaxNRemove() BST<int>: ";

  if(bst13.MaxNRemove() == 2){
    if(bst13.Root().Element() == 1)
      cout << "Max element = 2 has been removed, Correct!"<<endl;
  }
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test MaxNRemove() BST<int>: ";

  if(bst13.MaxNRemove() == 1){
    if(bst13.Empty())
       cout << "Max element = 1 has been removed, Correct!"<<endl;
  }
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Max() BST<int>: ";
  if(bst.Max() == 9)
    cout <<"Max of the BST is "<< bst.Max() << ", Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test RemoveMax() BST<int>: ";
  bst.RemoveMax();
  if(bst.Size() == 6 && bst.Max()!= 9)
    cout << "Max element = 9 has been removed, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test MaxNRemove() BST<int>: ";
  if(bst.MaxNRemove() == 8)
    cout << "Max element = 8 has been removed, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Predecessor() BST<int>: ";
  lasd::BST<int> bst16;
  bst16.Insert(5);
  bst16.Insert(3);
  bst16.Insert(7);
  bst16.Insert(4);
  bst16.Insert(11);
  bst16.Insert(18);
  bst16.Insert(6);
  bst16.Insert(9);
  bst16.Insert(14);
  bst16.Insert(1);

  cout<< "Predecessor of 5 is "<< bst16.Predecessor(5)<<endl;
  if(bst16.Predecessor(5) == 4)
    cout << "Predecessor of 5 is 4, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Predecessor() BST<int>: ";
  if(bst16.Predecessor(3) == 1)
    cout << "Predecessor of 3 is 1, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<< "Predecessor of 7 is "<< bst16.Predecessor(7)<<endl;

  cout<<"("<< ++numTest<< ")"<< " Test Predecessor() BST<int>: ";
  if(bst16.Predecessor(7) == 6)
    cout << "Predecessor of 7 is 6, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

    cout<< "Predecessor of 14 is "<< bst16.Predecessor(14)<<endl;

  cout<<"("<< ++numTest<< ")"<< " Test Predecessor() BST<int>: ";
  if(bst16.Predecessor(14) == 11)
    cout << "Predecessor of 4 is 3, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Predecessor() BST<int>: ";
  if(bst16.Predecessor(18) == 14)
    cout << "Predecessor of 18 is 14, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test PredecessorNRemove() BST<int>: ";
  lasd::BST<int> bst14(list4);

  if(bst14.PredecessorNRemove(2) == 1){
    if(bst14.Root().Element() == 2)
      cout << "Predecessor of 2 was 1, it has been removed, Correct!"<<endl;
  }
  else{
      cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }


  lasd::BST<int> bst15;
  cout<<"("<< ++numTest<< ")"<< " Test PredecessorNRemove() BST<int>: ";
  bst15.Insert(3);
  bst15.Insert(1);
  bst15.Insert(6);
  
  if(bst15.PredecessorNRemove(3) == 1){
    if(bst15.Root().Element() == 3)
      cout << "Predecessor of 3 was 1, it has been removed, Correct!"<<endl;
  }
  else{
      cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  
  lasd::BST<int> bst18;
  bst18.Insert(5);
  bst18.Insert(3);
  bst18.Insert(7);
  bst18.Insert(4);
  bst18.Insert(11);
  bst18.Insert(18);
  bst18.Insert(6);
  bst18.Insert(9);
  bst18.Insert(14);
  bst18.Insert(1);

  cout<<"("<< ++numTest<< ")"<< " Test Successor() BST<int>: ";
  cout<< "Successor of 5 is "<< bst18.Successor(5)<<endl;
  if(bst18.Successor(5) == 6)
    cout << "Successor of 5 is 6, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Successor() BST<int>: ";
  cout<< "Successor of 3 is "<< bst18.Successor(3)<<endl;
  if(bst18.Successor(3) == 4)
    cout << "Successor of 3 is 4, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Successor() BST<int>: ";
  cout<< "Successor of 7 is "<< bst18.Successor(7)<<endl;
  if(bst18.Successor(7) == 9)
    cout << "Successor of 7 is 9, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Successor() BST<int>: ";
  cout<< "Successor of 14 is "<< bst18.Successor(14)<<endl;
  if(bst18.Successor(14) == 18)
    cout << "Successor of 14 is 18, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Successor() BST<int>: ";
  cout<< "Successor of 1 is "<< bst18.Successor(1)<<endl;
  if(bst18.Successor(1) == 3)
    cout << "Successor of 1 is 3, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }




  cout<<"("<< ++numTest<< ")"<< " Test SuccessorNRemove() BST<int>: ";
  lasd::BST<int> bst17;
  bst17.Insert(5);
  bst17.Insert(3);
  bst17.Insert(7);

  if(bst17.SuccessorNRemove(5) == 7){
    if(bst17.Root().right== nullptr)
       cout << "Successor of 5 was 7, it has been removed, Correct!"<<endl;
  }
  else{
     cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Insert() BST<int>: ";
  lasd::BST<int> bst20;

  bst20.Insert(4);
  if(bst20.Root().Element() == 4)
    cout<< "Inserimento dell'elemento 4 riuscito, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Insert() BST<int>: ";
  bst20.Insert(2);

  if(bst20.Root().left->Element() == 2)
    cout<< "Inserimento dell'elemento 2 riuscito, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Insert() BST<int>: ";
  bst20.Insert(6);

  if(bst20.Root().right->Element() == 6)
    cout<< "Inserimento dell'elemento 6 riuscito, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Insert() BST<int>: ";
  bst20.Insert(3);

  if(bst20.Root().left->right->Element() == 3)
    cout<< "Inserimento dell'elemento 3 riuscito, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Insert() BST<int>: ";
  bst20.Insert(5);

  if(bst20.Root().right->left->Element() == 5)
    cout<< "Inserimento dell'elemento 5 riuscito, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }


  cout<<"("<< ++numTest<< ")"<< " Test Remove() BST<int>: ";
  bst20.Remove(5);
  if(bst20.Root().right->left == nullptr)
    cout<< "Cancellazione dell'elemento 5 riuscita, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Remove() BST<int>: ";
  bst20.Remove(2);
  if(bst20.Root().left->Element() == 3 && bst20.Root().left->right == nullptr)
    cout<< "Cancellazione dell'elemento 2 riuscita, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Remove() BST<int>: ";
  bst20.Remove(4);
  if(bst20.Root().Element() == 6 && bst20.Root().right == nullptr)
    cout<< "Cancellazione dell'elemento 4 riuscita, Correct!"<<endl;
  else{
    cout<< "Error!"<< endl; errors++; TestPassed &= false;
  }

  cout << "END OF BST<int> TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}


void mytest2() {
  cout<<endl;
  cout<< " ~ BEGIN MYTEST 2 ~ " << endl<<endl;
  cout<< (TestBinaryTreeLink() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<<(TestBinaryTreeVec() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<<(TestBST() ? "All Passed!" : "Error!")<<endl<<endl;
  cout<< " ~ END MYTEST 2 ~ " << endl;
}

bool testHashTableConstructors(){
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;
  cout << "BEGIN OF HashTable Constructor TEST " << endl;

  cout<<"("<< ++numTest<< ")"<< " Test Default Constructor HashTableCls<int>: ";
  lasd::HashTableClsAdr<int> htCls;
  
  if(htCls.Size() == 0 && htCls.TableSize() == 16)
    cout << " size is " << htCls.Size() << " and tableSize is "<< htCls.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Default Constructor HashTableOpn<int>: ";
  lasd::HashTableOpnAdr<int> htOpn;
  if(htOpn.Size() == 0 && htOpn.TableSize() == 16)
    cout << " size is " << htOpn.Size() << " and tableSize is "<< htOpn.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> with a given size: ";
  lasd::HashTableClsAdr<int> htCls1(64);

  if(htCls1.Size() == 0 && htCls1.TableSize() == 64)
    cout << " size is " << htCls1.Size() << " and tableSize is "<< htCls1.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> with a given size: ";
  lasd::HashTableOpnAdr<int> htOpn1(64);
  
  if(htOpn1.Size() == 0 && htOpn1.TableSize() == 64)
    cout << " size is " << htOpn1.Size() << " and tableSize is "<< htOpn1.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a Traversable Container: List<int>:";
  lasd::List<int> list;
  for(ulong i=0; i<100; i++) list.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls2(list);

  if(htCls2.Size() == 100 && htCls2.TableSize() == 128)
        cout << " size is " << htCls2.Size() << " and tableSize is "<< htCls2.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a Traversable Container: List<int>:";
  lasd::HashTableOpnAdr<int> htOpn2(list);

  if(htOpn2.Size() == 100 && htOpn2.TableSize() == 256)
        cout << " size is " << htOpn2.Size() << " and tableSize is "<< htOpn2.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a Traversable Container: Vector<int>:";
  lasd::Vector<int> vec(200);
  for(ulong i=0; i<200; i++) vec[i] = i;
  lasd::HashTableClsAdr<int> htCls3(vec);

  if(htCls3.Size() == 200 && htCls3.TableSize() == 256)
      cout << " size is " << htCls3.Size() << " and tableSize is "<< htCls3.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a Traversable Container: Vector<int>:";
  lasd::HashTableOpnAdr<int> htOpn3(vec);

  if(htOpn3.Size() == 200 && htOpn3.TableSize() == 512)
      cout << " size is " << htOpn3.Size() << " and tableSize is "<< htOpn3.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }


  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a Mappable Container: Vector<int>:";
  lasd::HashTableClsAdr<int> htCls4(std::move(vec));

  if(htCls4.Size() == 200 && htCls4.TableSize() == 256)
      cout << " size is " << htCls4.Size() << " and tableSize is "<< htCls4.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
 
  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a Mappable Container: Vector<int>:";
  lasd::Vector<int> vec1(400);
  for(ulong i=0; i<400; i++) vec1[i] = i;
  lasd::HashTableOpnAdr<int> htOpn4(std::move(vec1));

  if(htOpn4.Size() == 400 && htOpn4.TableSize() == 1024)
        cout << " size is " << htOpn4.Size() << " and tableSize is "<< htOpn4.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a Mappable Container: List<int>:";
  lasd::HashTableClsAdr<int> htCls5(std::move(list));

  if(htCls5.Size() == 100 && htCls5.TableSize() == 128)
      cout << " size is " << htCls5.Size() << " and tableSize is "<< htCls5.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a Mappable Container: List<int>:";
  lasd::List<int> list1;
  for(ulong i=0; i<200; i++) list1.InsertAtBack(i);
  lasd::HashTableOpnAdr<int> htOpn6(std::move(list1));

  if(htOpn6.Size() == 200 && htOpn6.TableSize() == 512)
        cout << " size is " << htOpn6.Size() << " and tableSize is "<< htOpn6.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a TC and with a given size:";
  lasd::List<int> list2;
  for(ulong i=0; i<50; i++) list2.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls6(64, list2);

  if(htCls6.Size() == 50 && htCls6.TableSize() == 64)
      cout << " size is " << htCls6.Size() << " and tableSize is "<< htCls6.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a TC and with a given size:";
  lasd::List<int> list3;
  for(ulong i=0; i<50; i++) list3.InsertAtBack(i);
  lasd::HashTableOpnAdr<int> htOpn10(64, list3);

  if(htOpn10.Size() == 50 && htOpn10.TableSize() == 128)
      cout << " size is " << htOpn10.Size() << " and tableSize is "<< htOpn10.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableCls<int> obtained from a MC and with a given size:";
  lasd::Vector<int> vec2(50);
  for(ulong i=0; i<50; i++) vec2[i] = i;
  lasd::HashTableClsAdr<int> htCls11(64, std::move(vec2));

  if(htCls11.Size() == 50 && htCls11.TableSize() == 64)
      cout << " size is " << htCls11.Size() << " and tableSize is "<< htCls11.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test HashTableOpn<int> obtained from a MC and with a given size:";
  lasd::Vector<int> vec3(50);
  for(ulong i=0; i<50; i++) vec3[i] = i;
  lasd::HashTableOpnAdr<int> htOpn11(64, std::move(vec3));

  if(htOpn11.Size() == 50 && htOpn11.TableSize() == 128)
      cout << " size is " << htOpn11.Size() << " and tableSize is "<< htOpn11.TableSize()<< ", Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy Constructor HashTableCls<int>:";
  lasd::HashTableClsAdr<int> htCls7(htCls5);

  if(htCls7 == htCls5)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy Constructor HashTableOpn<int>:";
  lasd::HashTableOpnAdr<int> htOpn7(htOpn6);
  
  if(htOpn7 == htOpn6)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move Constructor HashTableCls<int>:";
  lasd::HashTableClsAdr<int> htCls8(std::move(htCls7));

  if(htCls8 == htCls5 && htCls7.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move Constructor HashTableOpn<int>:";
  lasd::HashTableOpnAdr<int> htOpn8(std::move(htOpn7));

  if(htOpn8 == htOpn6 && htOpn7.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout << "END OF Hash Table Constructor TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;

}

bool TestHashTableAssignments(){
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout << "BEGIN OF HashTable Assignments TEST " << endl;

  cout<<"("<< ++numTest<< ")"<< " Test Copy Assignment HashTableCls<int>:";
  lasd::HashTableClsAdr<int> htCls;
  lasd::List<int> list;
  for(ulong i=0; i<100; i++) list.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls1(list);

  htCls = htCls1;
  if(htCls == htCls1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Copy Assignment HashTableOpn<int>:";
  lasd::HashTableOpnAdr<int> htOpn;
  lasd::HashTableOpnAdr<int> htOpn1(list);

  htOpn = htOpn1;
  if(htOpn == htOpn1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move Assignment HashTableCls<int>:";
  lasd::HashTableClsAdr<int> htCls2;
  lasd::List<int> list1;
  for(ulong i=0; i<100; i++) list1.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls3(list1);

  htCls2 = std::move(htCls3);
  if(htCls2 == htCls1 && htCls3.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Move Assignment HashTableOpn<int>:";
  lasd::HashTableOpnAdr<int> htOpn2;
  lasd::HashTableOpnAdr<int> htOpn3(list1);

  htOpn2 = std::move(htOpn3);
  if(htOpn2 == htOpn1 && htOpn3.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<" END OF HashTable Assignments TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}

bool TestHashTableClsFunction(){
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout << "BEGIN OF HashTableClsAdr<int> Functions TEST " << endl;

  lasd::HashTableClsAdr<int> htCls;
  lasd::List<int> list;
  for(ulong i=0; i<100; i++) list.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls1(list);

  for(ulong i = 0; i<100 ; i+=7){
    cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableClsAdr<int>:";  
    if(htCls1.Exists(i))
      cout << "Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableClsAdr<int>:";
  if(!htCls1.Exists(100))
    cout << " Value 100 not exists. Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableClsAdr<int>:";
  if(!htCls1.Exists(572))
    cout << " Value 572 not exists. Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  lasd::HashTableClsAdr<int> htCls2;
  for(ulong i = 0; i<200 ; i+=13){
    cout<<"("<< ++numTest<< ")"<< " Test Insert() HashTableClsAdr<int>:";
    htCls2.Insert(i);
    if(htCls2.Exists(i))
        cout<< "Insertion of value "<< i << " Correct!" << endl;
  
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  for(ulong i = 0; i<50; i+=3){
    htCls.Insert(i);
  }

  for(ulong i = 0; i<50; i+=3){
    cout<<"("<< ++numTest<< ")"<< " Test Remove() HashTableClsAdr<int>:";
    htCls.Remove(i);
    if(!htCls.Exists(i))
      cout<< "Removal of value "<< i << " Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<"("<< ++numTest<< ")"<< " Test Empty() HashTableClsAdr<int>:";
  if(htCls.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Clear() HashTableClsAdr<int>:";
  htCls2.Clear();
  if(htCls2.Empty() && htCls2.TableSize() == 32)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  
  cout<<"("<< ++numTest<< ")"<< " Test Clear() HashTableClsAdr<int>:";
  htCls1.Clear();
  if(htCls2 == htCls1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  for(ulong i = 16; i<1024; i*=2){
    cout<<"("<< ++numTest<< ")"<< " Test Resize() HashTableClsAdr<int>:";
    htCls2.Resize(i);
    if(htCls2.TableSize() == i)
      cout << "Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<"("<< ++numTest<< ")"<< " Test Resize() HashTableClsAdr<int>:";
  htCls2.Resize(0);
  if(htCls2.TableSize() == 16)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Resize() HashTableClsAdr<int>:";
  for(ulong i = 0; i<50; i++)
    htCls2.Insert(i);
  if(htCls2.Size() == 50 && htCls2.TableSize() == 64)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  

  cout<<"("<< ++numTest<< ")"<< " Test Resize() HashTableClsAdr<int>:";
  for(ulong i = 0; i<50; i++)
    htCls2.Remove(i);

  if(htCls2.Size() == 0 && htCls2.TableSize() == 16)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<" END OF HashTableClsAdr<int> Functions TEST: ("<< errors << "/" << numTest  << ") " ;

  return TestPassed;

}

bool TestHashTableComparison(){
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0; 

  cout << "BEGIN OF HashTable Comparison Operators TEST " << endl;

  cout<<"("<< ++numTest<< ")"<< " Test operator == empty HashTableClsAdr<int>:";
  lasd::HashTableClsAdr<int> htCls;
  lasd::HashTableClsAdr<int> htCls1;

  if(htCls == htCls1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test operator == empty HashTableOpnAdr<int>:";
  lasd::HashTableOpnAdr<int> htOpn;
  lasd::HashTableOpnAdr<int> htOpn1;

  if(htOpn == htOpn1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableClsAdr<int> are equal: ";
  lasd::List<int> list;
  for(ulong i=0; i<100; i++) list.InsertAtBack(i);
  lasd::HashTableClsAdr<int> htCls2(list);
  lasd::HashTableClsAdr<int> htCls3(list);

  if(htCls2 == htCls3)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableOpnAdr<int> are equal: ";
  lasd::HashTableOpnAdr<int> htOpn2(list);
  lasd::HashTableOpnAdr<int> htOpn3(list);

  if(htOpn2 == htOpn3)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableClsAdr<int> are not equal: ";
  lasd::HashTableClsAdr<int> htCls4(list);
  lasd::HashTableClsAdr<int> htCls5(list);
  htCls5.Remove(0);
  htCls5.Remove(50);
  
  if(!(htCls4 == htCls5))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableOpnAdr<int> are not equal: ";
  lasd::HashTableOpnAdr<int> htOpn4(list);
  lasd::HashTableOpnAdr<int> htOpn5(list);
  htOpn5.Remove(0);
  htOpn5.Remove(50);

  if(!(htOpn4 == htOpn5))
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableClsAdr<int> are equal: ";
  lasd::HashTableClsAdr<int> htCls6(list);
  lasd::HashTableClsAdr<int> htCls7(list);

  htCls7.Resize(200);
  if(htCls6 == htCls7)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " The two HashTableOpnAdr<int> are equal: ";
  lasd::HashTableOpnAdr<int> htOpn6(list);
  lasd::HashTableOpnAdr<int> htOpn7(list);

  htOpn7.Resize(200);
  if(htOpn6 == htOpn7)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<" END OF HashTable Comparison Operators TEST: ("<< errors << "/" << numTest  << ") " ;
  return TestPassed;
}

bool TestHashTableOpnFunction(){
  bool TestPassed = true;
  ulong numTest = 0;
  ulong errors = 0;

  cout << "BEGIN OF HashTableOpnAdr<int> Functions TEST " << endl;

  lasd::HashTableOpnAdr<int> htOpn;
  lasd::List<int> list;
  for(ulong i=0; i<100; i++) list.InsertAtBack(i);
  lasd::HashTableOpnAdr<int> htOpn1(list);

  for(ulong i = 0; i<100 ; i+=7){
    cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableOpnAdr<int>:";  
    if(htOpn1.Exists(i))
      cout << "Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableOpnAdr<int>:";
  if(!htOpn1.Exists(100))
    cout << " Value 100 not exists. Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Exists() HashTableOpnAdr<int>:";
  if(!htOpn1.Exists(572))
    cout << " Value 572 not exists. Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  lasd::HashTableOpnAdr<int> htOpn2;
  for(ulong i = 0; i<200 ; i+=13){
    cout<<"("<< ++numTest<< ")"<< " Test Insert() HashTableOpnAdr<int>:";
    htOpn2.Insert(i);
    if(htOpn2.Exists(i))
        cout<< "Insertion of value "<< i << " Correct!" << endl;
  
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  for(ulong i = 0; i<50; i+=3){
    htOpn.Insert(i);
  }

  for(ulong i = 0; i<50; i+=3){
    cout<<"("<< ++numTest<< ")"<< " Test Remove() HashTableOpnAdr<int>:";
    htOpn.Remove(i);
    if(!htOpn.Exists(i))
      cout<< "Removal of value "<< i << " Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<"("<< ++numTest<< ")"<< " Test Empty() HashTableOpnAdr<int>:";
  if(htOpn.Empty())
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  cout<<"("<< ++numTest<< ")"<< " Test Clear() HashTableOpnAdr<int>:";
  htOpn2.Clear();
  if(htOpn2.Empty() && htOpn.TableSize() == 16)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }
  
  cout<<"("<< ++numTest<< ")"<< " Test Clear() HashTableOpnAdr<int>:";
  htOpn1.Clear();
  if(htOpn2 == htOpn1)
    cout << "Correct!" << endl;
  else{
    cout << "Error!" << endl; TestPassed &= false; errors++;
  }

  for(ulong i = 16; i<1024; i*=2){
    cout<<"("<< ++numTest<< ")"<< " Test Resize() HashTableOpnAdr<int>:";
    htOpn2.Resize(i);
    if(htOpn2.TableSize() == i)
      cout << "Correct!" << endl;
    else{
      cout << "Error!" << endl; TestPassed &= false; errors++;
    }
  }

  cout<<" END OF HashTableOpnAdr<int> Functions TEST: ("<< errors << "/" << numTest  << ") " ;

  return TestPassed;

}


void mytest3() {
  cout<<endl;
  cout<< " ~ BEGIN MYTEST 3 ~ " << endl<<endl;
  cout<< (testHashTableConstructors() ? "All Passed!" : "Error!" )<< endl<<endl;
  cout<<(TestHashTableAssignments() ? "All Passed!" : "Error!" ) << endl<<endl;
  cout<<(TestHashTableComparison() ? "All Passed!" : "Error!" ) << endl<<endl;
  cout<<(TestHashTableClsFunction() ? "All Passed!" : "Error!" ) << endl<<endl;
  cout<<(TestHashTableOpnFunction() ? "All Passed!" : "Error!" ) << endl<<endl;
  cout<< " ~ END MYTEST 3 ~ " << endl;
}

#endif



  


