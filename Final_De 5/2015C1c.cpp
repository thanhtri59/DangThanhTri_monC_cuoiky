class Singleton {
public:
    // ham get 
    static Singleton& getInstance() {
        static Singleton instance; // tao duy nhat 1 lan
        return instance;
    }

    // gan 2 operator = delete de ngan chan viec sao chep hay gan inst, dam bao khong the bi copy hay =
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

private:
    Singleton() {} // cho constructor vao` private de tranh truong hop goi no tu ben ngoai class
};
