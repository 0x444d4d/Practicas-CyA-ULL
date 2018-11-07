
namespace CyA {

class ladrillo{

  private:
    int size_;

  public:
    ladrillo() {};
    ladrillo(int x) { size_ = x; };
    ~ladrillo() {};

    int get_size(void) { return size_; };
};

}

