#include "Mesh.h"

Mesh::Mesh(const string &filename) {
        ifstream file(filename.c_str(), ios::binary);
        if (!file)
                throw runtime_error("Cannot open model " + filename);

        uint32_t magic;
        uint16_t secHead;
        uint16_t secSize;
        void *data;

        file.read((char*)&magic, 4);
        if (magic != 0x584F4DFE)
                throw runtime_error(filename + " isn't valid Moxie");

        while (!file.eof()) {
                file.read((char*)&secHead, 2);
                file.read((char*)&secSize, 2);
                switch(secHead) {
                        case 0xE54D:
                                m_vertices = new glm::vec3[secSize/3];
                                file.read((char*)m_vertices,
                                                secSize/sizeof(float));
                                break;
                        case 0xE64D:
                                m_texCoords = new glm::vec2[secSize/2];
                                file.read((char*)m_texCoords,
                                                secSize/sizeof(float));
                                break;
                        case 0xE74D:
                                m_normals = new glm::vec3[secSize/3];
                                file.read((char*)m_normals,
                                                secSize/sizeof(float));
                                break;
                        case 0xE84D:
                                // Still working on this
                                break;
                        default:
                                break;
                }
        }
        file.close();

        unsigned int sizeVerts = sizeof(float) * 3 * sizeof(m_vertices);
        unsigned int sizeTexCs = sizeof(float) * 2 * sizeof(m_texCoords);
        unsigned int sizeNorms = sizeof(float) * 3 * sizeof(m_normals);
        unsigned int sizeIndxs = sizeof(float) * 3 * sizeof(m_indices);

        // Needs testing with Moxie format
        glGenVertexArrays(1, &m_VAO);
        glBindVertexArray(m_VAO);
        glGenBuffers(NUM_BUFFERS, m_VABs);

        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[POSITION_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeVerts, m_vertices, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[TEXCOORD_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeTexCs, m_texCoords, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, m_VABs[NORMAL_VB]);
        glBufferData(GL_ARRAY_BUFFER, sizeNorms, m_normals, GL_STATIC_DRAW);
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_VABs[INDEX_VB]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeIndxs, m_indices,
                        GL_STATIC_DRAW);

        glBindVertexArray(0);
}

void Mesh::Draw(const float x, const float y, const float z) {
        glm::vec3 pos(x, y, z);
        pos.x = x;
        pos.y = y;
        pos.z = z;

        glBindVertexArray(m_VAO);
        glDrawElementsBaseVertex(GL_TRIANGLES, sizeof(m_indices),
                        GL_UNSIGNED_INT, 0, 0);
        glBindVertexArray(0);
}

Mesh::~Mesh() {
        delete[] m_vertices;
        delete[] m_texCoords;
        delete[] m_normals;
        glDeleteBuffers(NUM_BUFFERS, m_VABs);
        glDeleteVertexArrays(1, &m_VAO);
}
