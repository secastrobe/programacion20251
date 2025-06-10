#include <iostream>
#include <valarray>

void producto_punto(std::valarray<int> &v1, std::valarray<int> &v2);

int main()
{
  std::valarray<int> data = {0,1,2,3,4,5,6,7,8,9};
  std::valarray<int> data2 = {0,1,2,3,4,5,6,7,8,9};


  std::cout << "Initial valarray: ";
  for(int n: data) std::cout << n << ' ';
  std::cout << '\n';

  data[data > 5] = -1; // valarray<bool> overload of operator[]
  // the type of data>5 is std::valarray<bool>
  // the type of data[data>5] is std::mask_array<int>

  std::cout << "After v[v>5]=-1:  \n";
  for(std::size_t n = 0; n < data.size(); ++n)
    std::cout << data[n] << ' ';  // regular operator[]
  std::cout << '\n';

  producto_punto(data, data2);
}

void producto_punto(std::valarray<int> &v1, std::valarray<int> &v2){
  std::cout<< "Producto punto: " << (v1*v2).sum() << "\n";
}