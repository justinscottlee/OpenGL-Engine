#version 330 core

in vec3 position;
out vec3 pass_color;

void main() {
    gl_Position = vec4(position, 1.0);
    pass_color = vec3(position.x + 0.5, position.y + 0.5, position.z + 0.5);
}