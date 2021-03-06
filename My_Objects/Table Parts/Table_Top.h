#include <vector>
#include "../../BufferObject.h"
using namespace std;

class Table_Top{
private:
    const float length = 2;
    const float height = 0.075;
    const float width = 1.5;
    //Top & Bottom Color
    float color1 = 0.70;
    float color2 = 0.57;
    float color3 = 0.51;
    //Siding Color
    float color4 = 0.08;
    float color5 = 0.08;
    float color6 = 0.10;
    GLuint v_buf, i_buf, c_buf;
    vector<float> vertices;
    vector<GLushort> indexes;
    vector<GLfloat> color;

public:
    ~Table_Top();
    void build();
    void render() const;
};