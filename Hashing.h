

class custom_hash {
public  :
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


int get_hash(string str) {
    const int mod =  1e9 +  7 , p =  257  ;
    int ret = 0  , po = 1 ;

    for (auto &ch  : str){
        ret = (ret + (ch * po))%mod ;
        po = (po * p )%mod ;
    }

    return ret;

}
