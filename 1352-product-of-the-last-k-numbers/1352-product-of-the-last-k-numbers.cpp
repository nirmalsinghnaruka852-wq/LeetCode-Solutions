class ProductOfNumbers {
public:
    //  simplest One
    vector<int> nums ; 
    ProductOfNumbers() {
        this->nums = {};
        
    }
    
    void add(int num) {
          this->nums.push_back(num);
          return ; 
    }
    
    int getProduct(int k) {
        int result =  1; 
        for(int index = this->nums.size()-1 ; index>= 0 && k > 0 ; index-- ){
          result *= this->nums[index];
          k-- ;
        }
        return result ; 
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */