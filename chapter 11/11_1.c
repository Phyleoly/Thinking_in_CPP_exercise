typedef struct {} bird;
typedef struct {} rock;

int main() {
    bird* b;
    rock* r;
    void* v;
    v = r;
    b = v;
    
    return 0;
}