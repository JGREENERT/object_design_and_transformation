#include <vector>
#include "../../BufferObject.h"
using namespace std;

class Table_Crossbar{
private:
    const float length = 0.075;
    const float height = 0.075;
    const float width = 0.15;
    int color1 = 0;
    int color2 = 0;
    int color3 = 0;
    GLuint v_buf, i_buf, c_buf;
    vector<float> vertices;
    vector<GLushort> indexes;
    vector<GLfloat> color;

public:
    ~Table_Crossbar();
    void build();
    void render() const;
};