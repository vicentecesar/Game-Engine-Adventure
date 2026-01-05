float random(vec2 co) {
    float a = 12.9898;
    float b = 78.233;
    float c = 43758.5453;
    float dt = dot( co.xy ,vec2(a,b) );
    float sn = mod(dt, 3.14);
    return fract(sin(sn) * c);
}

vec3 importanceSample_GGX(vec2 Xi, float roughness, vec3 normal) {
    /*
        GPU's como a intel iris xe possuem uma pior precisão numerica. Logo, é necessario uma pequena correção no shader.
        Como a engine no momento está sendo desenvolvido em um computador com uma GPU mais moderna, deixaremos isso
        comentado, para gerar tabelas de pre-computação com melhor precisão numerica.
        float alpha = max(roughness * roughness, 0.001);
    */
    float alpha = roughness * roughness;
    float phi = 2.0 * PI * Xi.x + random(normal.xz) * 0.1;
    float cosTheta = sqrt((1.0 - Xi.y) / (1.0 + (alpha * alpha - 1.0) * Xi.y));
    float sinTheta = sqrt(1.0 - cosTheta * cosTheta);
    vec3 H = vec3(sinTheta * cos(phi), sinTheta * sin(phi), cosTheta);
    vec3 up = abs(normal.z) < 0.999 ? vec3(0.0, 0.0, 1.0) : vec3(1.0, 0.0, 0.0);
    vec3 tangentX = normalize(cross(up, normal));
    vec3 tangentY = normalize(cross(normal, tangentX));
    return normalize(tangentX * H.x + tangentY * H.y + normal * H.z);
}