#include <iostream>
#include <cstdlib> //The C++ STL (C++ STandard Library)
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool myWay(pair<int, int> a, pair<int, int> b)
{
  return ((a.second == b.second) ? a.first > b.first : a.second < b.second);
}
int main()
{
//pair
{
  //int, int pair:
  pair<int, int> p = {1, 5};
  cout << p.first << " " << p.second << "\n";
  //pair, int pair:
  pair<pair<int, int>, int> pp = {{1, 7}, 5};
  cout << pp.first.second << " " << pp.first.first << " " << pp.second << "\n";
  //array of pairs:
  pair<int, int> parr[] = {{1, 2}, {2, 3}, {3, 4}};
  cout << parr[0].second << " " << parr[1].second << " " << parr[2].second << "\n";
}
//vector
{
  //normal initialisation / empty vector:
  vector<int> v;
  v.push_back(1); //v becomes {1}
  v.emplace_back(2); //v becomes {1, 2}
  //a vector of pairs:
  vector<pair<int, int>> vp;
  vp.emplace_back(1, 2); //vp becomes {{1, 2}}
  vp.push_back({3, 4}); //vp becomes {{1, 2}, {3, 4}}
    /* Notice the different syntax for emplace_back and push_back.
       Note: emplace_back does not behave the same with more branched vectors */
  //Other initialisations of a vector:
  vector<int> v1(5); //vector of size 5 with every member as 0/garbage value(based on the compiler).
  vector<int> v2(5, 100); //vector of size 5 with every member as 100.
  vector<int> v3(v2); //vector which is an exact copy of v2 is created.
  //indexing:
  cout << v[0] << " " << v2.back() << "\n"; //normal indexing like an array but back() returns the last element
}
//iterator
{
  vector<int> vi = {10, 20, 30, 40};
  vector<int>::iterator it = vi.begin(); //iterator pointing to the first element in a vector
  cout << *it << "\n"; //works just like dereferencing a normal pointer, prints vi[0]
  it++; //changes the address its pointing towards to the next element in the vector
  cout << *it << "\n";
  it = vi.end(); //points to the (vacant) memory address after the last element of the vector
  //reverse_iterator:
  vector<int>::reverse_iterator it1;
  it1 = vi.rend(); //points to the (vacant) memory address before the first element of the vector
  it1 = vi.rbegin(); //points to the last element of the vector
  cout << *it1 << "\n";
  it1++; //points to the second last element of the vectore (reverse_iterators go back in address for increments)
  cout << *it1 << "\n";
  //const_iterator:
  vector<int>::const_iterator it2; //an iterator pointing to a constant value
  it2 = vi.cbegin(); //same as begin but for const_iterators
  cout << *it2 << "\n";
  it2 = vi.cend(); //same as end but for const_iterators
}
//more vector stuff
{
  vector<int> vi = {10, 20, 30, 40};
  //ways to print the vector:
    //for(vector<int>::iterator it = vi.begin(); it != vi.end(); it++)
  for(auto it = vi.begin(); it != vi.end(); it++) //auto tells the compiler to deduce the type of the variable via the initialisation
  {
    cout << *it << " ";
  }
  for(auto i : vi) //for-each loop where i is the integers in vi
  {
    cout << i << " ";
  }
  //other member functions:
  vector<int> vm = {13, 15, 17, 25};
  cout << "\n" << vm[1] << " ";
  vm.erase(vm.begin() + 1); //deletes the index and value being pointed to by the iterator given
  cout << vm[1] << "\n";
  vm.erase(vm.begin(), vm.begin() + 2); //range based erase(), deletes in range [left iterator, right iterator)
  vm.insert(vm.begin(), 300); //adds a new element after the given iterator with value given
  vm.insert(vm.begin() + 1, 2, 19); //adds specified number of elements with specified value(s) after the given iterator
  vector<int> vo(3, 50);
  vm.insert(vm.begin(), vo.begin(), vo.end()); //inserts the elements of another DS specified by the iterators, after the given iterator
  vm.pop_back(); //erases the last element
  for(auto i : vm)
  {
    cout << i << " ";
  }
  vm.swap(vo); //swaps the vectors
  cout << "\n" << vm.size() << "\n"; //gives the number of elements in a vector
  vm.clear(); //erases the entire vector
  cout << vm.empty() << "\n"; //checks if the vector is empty or not
}
//list
{
  list<int> ls;
  ls.push_back(2);
  ls.emplace_back(4);
  //Lists have all the functions in vectors but also support push_front(), emplace_front(), pop_front(), front().
  ls.push_front(5);
  ls.emplace_front(13);
  for(auto i : ls) //Lists do not have indexes (unordered data structure)
  {
    cout << i << " ";
  }
  cout << "\n";
  /*Lists are only preferred over vectors when:
    front functions are required, otherwise Lists are way worse.*/
}
//deque
{
  deque<int> dq;
  dq.push_front(14);
  dq.emplace_front(12);
  for(auto i : dq)
  {
    cout << i << " ";
  }
  cout << "\n";
  //exact same member functions as in lists
  /*Deque are basically segmented vectors, therefore better for random positions
    Also. just like lists, it is used over vectors if front functions are required*/
}
//stack
{
  stack<int> st;
  st.push(1); //adds element to the stack (at the front)
  st.push(2);
  st.emplace(3);
  cout << st.top() << " "; //returns the last element added to the stack
  st.pop(); //removes the last element added to the stack
  cout << st.size() << " ";
  stack<int> stx;
  st.swap(stx);
  cout << st.empty() << "\n";
}
//queue
{
  queue<int> q;
  q.push(4); //adds element to the queue(at the end)
  q.emplace(7);
  q.back() += 5; //returns last element
  cout << q.back() << " ";
  cout << q.front() << " "; //returns first element
  q.pop(); //removes first element
  cout << q.front() << "\n";
}
//priority queue
{
  priority_queue<int> pq; //Elements are inserted such that a descending order is maintained
  pq.push(5); //{5}
  pq.emplace(2); //{5, 2}
  pq.push(10); //{10, 5, 2}
  pq.emplace(8); //{10, 8, 5, 2}
  cout << pq.top() << " "; //returns the first element
  pq.pop(); //removes the first element
  cout << pq.top() << " ";
  //Ascending version of a Priority Queue:
  priority_queue<int, vector<int>, greater<int> > pqA;
  pqA.push(5); //{5}
  pqA.emplace(2); //{2, 5}
  pqA.push(10); //(2, 5, 10)
  pqA.emplace(8); //{2, 5, 8, 10}
  cout << pqA.top() << "\n";
}
//set
{
  set<int> st;
  st.emplace(1); //{1}
  st.insert(5); //{1, 5}
  st.insert(3); //{1, 3, 5}
  st.insert(5); //Duplicate values are rejected by a set
  st.emplace(4); //{1, 3, 4, 5}
  auto seI = st.find(3); //O(logN) complexity, returns an iterator pointing to the value asked for
  auto seI2 = st.find(13); //if the value specified does not exist, returns st.end()
  cout << (seI2 == st.end()) << " "; //This bool returns false if the value specified to find() exists in the set.
  int cnt = st.count(1); //counts the number of specified value in the set, since values are unique, it returns 1 if the value exists in set and 0 otherwise.
  cout << cnt << " ";
  st.erase(4); //O(logN) complexity, finds and deletes specified value from the set.
  st.erase(seI); //O(1) complexity, deletes the element the iterator is pointing to
  st.erase(st.find(1), st.end()); //Deletes every element in the range [seI, sei2)
  cout << st.size() << "\n";
  //upper_bound and lower_bound for sets:
  set<int> st2 = {1, 3, 4, 5};
  auto ub1 = st2.upper_bound(3); //returns iterator pointing to the smallest element greater than specified value
  auto ub2 = st2.upper_bound(2); //whether the value itself exists in the set or not, does not matter
  auto ub3 = st2.upper_bound(7); //If the set does not have an element bigger than specified value, returns set.end()
  auto lb1 = st2.lower_bound(3); //returns iterator pointing to the specified value, if it exists in the set
  auto lb2 = st2.lower_bound(2); //if the value does not exist in the set, behaves like upper_bound()
  cout << *ub1 << " " << *ub2 << " " << *ub3 << "\n";
  cout << *lb1 << " " << *lb2 << "\n";
}
//multiset
{
  multiset<int> ms; //same as set, except it can store duplicates.
  ms.insert(1); //{1}
  ms.emplace(1); //{1, 1}
  ms.insert(1); //{1, 1, 1}
  ms.erase(ms.find(1)); //erases the specified occurence of the specified value
  cout << ms.count(1) << " "; //counts the occurences of the specified value
  ms.erase(1); //erases all occurences of the specified value
  //all other functions are essentially identical to sets.
}
//unordered_set
{
  unordered_set<int> us;
  us.insert(3);
  us.emplace(5);
  us.find(5); //O(1) complexity, much better than normal set.
  us.erase(3); //Also O(1) complexity.
  //Every function same as set, however due to not being ordered, lower_bound and upper_bound cannot be used.
}
//map
{
  map<int, int> mp;
  mp[2] = 7; //map[key] = value, assigns the specified value to the specified key, ie adds the {key, value} pair in the map.
  mp[1] = 5;
  //Both the following functions work same as seen in pairs
  mp.insert({14, 6}); //{key, value} inserted into map
  mp.emplace(13, 10);
  /*Therefore the current map looks like
  { {1, 5}
    {2, 7}
    {13, 10}
    {14, 6} }
  notice the automatic ascending sorting based on the keys*/
  cout << mp[13] << " " << mp[4] << "\n"; //map[key] returns the value linked to that key
  //since we asked for the value at a key that does not exist yet, the value is set to 0 or garbage in the map, then returned
  //similar to a vector of pairs for iterating
  for(auto it : mp)
  {
    cout << it.first << " , " << it.second << " : ";
  }
  auto it = mp.find(2); //returns iterator pointing to the pair with the specified key
  //points to end() if the key is not found in the map
  cout << "\n" << it->first << " - " << it->second << "\n";
}
//multimap
{
  multimap<int, int> mm;
  mm.emplace(1, 2);
  mm.emplace(1, 5);
  for(auto it : mm)
  {
    cout << it.first << " " << it.second << "\n";
  }
}
//unordered_map
{
  unordered_map<int, int> um;
  um.emplace(2, 7);
  um.emplace(1, 5);
  auto it = um.find(2); //takes constant time as compared to logarithmic in map
  cout << it->first << " " << it->second << "\n";
}
//other things
{
  int n = 5;
  int a[] = {5, 2, 0, 10, 3};
  sort(a, a+n); //sorts the array in the range [first, last) in ascending order
  for(int i = 0; i < n; i++)
    cout << a[i] << " ";
  sort(a, a+n, greater<int>()); //for descending order (greater is a template function made for comparing two numbers and choosing whats greater)
  for(int i = 0; i < n; i++)
    cout << a[i] << " ";
  //we can also do sort according to custom rules
  n = 3;
  pair<int, int> ap[] = {{1, 2}, {2, 1}, {4, 1}};
  sort(ap, ap+n, myWay);
  //[myWay] is the name of a boolean function which takes in 2 elements of the data type we are sorting and returns true if the first element is to come before the second element.
  cout << "\n";
  for(int i = 0; i < n; i++)
  {
    cout << ap[i].first << "-" << ap[i].second << " ";
  }
  int num = 15;
  int cnt = __builtin_popcount(num); //returns the number of set bits in the specified integer.
  cout << "\n" << cnt << "\n";
  //for very large numbers, use __builtin_popcountll()
  string s = "abc";
  do
  {
    cout << s + "\n";
  }
  while(next_permutation(s.begin(), s.end()));
  //the next_permutation function changes the specified range of data into its lexiographically next data
  //when used as a bool, next_permutation returns false when the current data is the lexiographical extreme.
  int max = *max_element(a, a+n);
  cout << max << "\n";
}
  cout << "~~The End~~";
}
