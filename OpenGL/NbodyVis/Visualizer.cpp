
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>


static void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

static void GLCheckError() {

    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL] " << error << std::endl;
    }
}



struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};


static ShaderProgramSource ParseShader(const std::string &filepath) {
    
    std::ifstream stream(filepath);


    enum class ShaderType {
        NONE = -1, vertex = 0, fragment = 1
    };

    
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;
    std::string line;
    while (getline(stream, line)) {
        if (line.find("#shader") != std::string::npos) {

            if (line.find("vertex") != std::string::npos) {
                type = ShaderType::vertex;
            }
            else if (line.find("fragment") != std::string::npos) {
                type = ShaderType::fragment;
            }
            
        }
        else {
            ss[(int)type] << line << '\n';
        }

    }

    return { ss[0].str() , ss[1].str() };
}


static unsigned int CompileShader(unsigned int type, const std::string& source) {

    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char *message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }

    return id;
}


static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader) {
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSwapInterval(1);

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cout << "Error! GLEW not working" << std::endl;
    }

    std::cout << "GL Version: " << glGetString(GL_VERSION) << std::endl;

    float positions[] = {
       -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f,  0.5f,
       -0.5f,  0.5f,
    };

    unsigned int indicies[] = {
        0,1,2,
        2,3,0
    };

    /// Vertex Buffer
    unsigned int buffer;
    glGenBuffers(1, &buffer); ///buffer variable is the ID of the buffer 
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 4 *2* sizeof(float), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0); // 0 = first attribute, 2 = size of vertex
     
    /// Index Buffer
    unsigned int ibo; //index buffer object
    glGenBuffers(1, &ibo); ///buffer variable is the ID of the buffer 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), indicies, GL_STATIC_DRAW);





    ShaderProgramSource source = ParseShader("myshader.shader");


    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
    glUseProgram(shader);

    int location = glGetUniformLocation(shader, "u_Color");
    assert(location != -1);
    
    float r = 0.0f;
    float increment = 0.0005f;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        
        ///glDrawArrays(GL_TRIANGLES, 0, 6); /// Draw call

        GLClearError();
        glUniform4f(location, r, 0.3f, 0.8f, 1.0f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
        GLCheckError();

        if (r > 1.0f) {
            increment = -0.0005f;
        }
        else if (r < 0.0f) {
            increment = 0.0005f;
        };

        r += increment;

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    ///glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}