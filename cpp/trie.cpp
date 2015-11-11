/************************************************************************************************

Trie implementation using std::map. Instead of using 26 char array, to make the trie space 
efficient, std::map is used. Allows constant time access and space efficiency.

************************************************************************************************/

#include <iostream>
#include <cstring>
#include <memory>
#include <map>
#include <vector>
#include <iterator>
#include <ctime>
#include <stack>
#include <tuple>

struct node {

   unsigned count = 0;
   std::map<char, node*> children;
};

class trie {

public:
 
   trie():root(new node), count(0) {}
   
   ~trie() {}

   void push(const char *str) {

      unsigned length = std::char_traits<char>::length(str);
      node *crawl = root;

      count++;

      for (unsigned level=0 ; level<length; ++level) {
         
         char index = str[level];
         
         if (crawl->children.find(index) == crawl->children.end())
            crawl->children[index] = new node;
         
         crawl = crawl->children[index];
      }
      
      crawl->count = count;
   }

   bool find(const char *str) { 
      
      unsigned length = std::char_traits<char>::length(str);
      node *crawl = root;

      for (unsigned level=0; level<length; ++level) {
         
         char index=str[level];
           
         if (crawl->children.find(index) == crawl->children.end())
            return 0;
         
         crawl = crawl->children[index];
      }
   
      return ((crawl != 0) && crawl->count); 
   }

   void print_trie() {
      print_trie(root,std::string(""));
      print_trie(root);
   }

   // Recursive function to print the trie content
   void print_trie(node *n, std::string str) {
      
      if (n->count)
         std::cout<<str<<std::endl;

      for (auto &child: n->children) {
         print_trie(child.second, str+child.first);
      }
   }

   // Iterative function to print the trie content
   void print_trie(node *n)  {
      //TODO
   }

private:
   node *root;
   unsigned count;
};

int main() {

   trie t;

   std::vector<std::string> arr{"this","that","these", "are", "any"};

   for (std::string s : arr)
      t.push(s.c_str());

   std::srand(time(0));
   auto it = arr.begin();

   std::advance(it,(rand()%arr.size()));
   arr.insert(it,std::string("the"));
   
   it = arr.begin();
   
   std::advance(it,(rand()%arr.size()));
   arr.insert(it,std::string("thermal"));

   it = arr.begin();

   std::advance(it,(rand()%arr.size()));
   arr.insert(it,std::string("ana"));
   
   for (std::string s : arr)
      if (t.find(s.c_str()))
         std::cout<<"FOUND\t"<<s<<std::endl;
      else
         std::cout<<"-----\t"<<s<<std::endl;

   t.print_trie();

   return 0;
}
