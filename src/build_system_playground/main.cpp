#include <iostream>
#include <mutex>
#include <shared_mutex>

using std::cout;
using std::endl;
using std::shared_mutex;
using std::shared_lock;

int main(int argc, char** argv)
{
  shared_mutex tmp_mutex;
  {
    shared_lock<shared_mutex> lock(tmp_mutex);
  }
  cout << "This is an example build system to play with." << endl;
  return 0;
}
