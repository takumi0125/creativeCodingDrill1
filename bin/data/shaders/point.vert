#version 120


void main() {
  gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
  gl_PointSize = (gl_Vertex.z + 200) * 0.1;
  gl_FrontColor = gl_Color;
}
