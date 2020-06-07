#include "IndexBuffer.h"
#include "Renderer.h"
#include <cassert>

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count) 
    : m_Count(count) 
{
    
    assert(sizeof(unsigned int) == sizeof(GLuint));
    
    glGenBuffers(1, &m_RenderId); ///buffer variable is the ID of the buffer 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count* sizeof(unsigned int), data, GL_STATIC_DRAW);

}
IndexBuffer::~IndexBuffer() {
    glDeleteBuffers(1, &m_RenderId);
}

void IndexBuffer::Bind() const{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderId);
}
void IndexBuffer::Unbind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}