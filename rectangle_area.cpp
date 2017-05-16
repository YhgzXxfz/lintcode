class Rectangle {
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    
    int getArea() {
        return width*height;
    }
private:
    int width, height;
};
