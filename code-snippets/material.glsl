struct MaterialGlobal {
    samplerCube irradianceMap;
    samplerCube radianceMap;
    sampler2D lut;
}

struct MaterialInstance {
    vec4 albedo;
    float metallic;
    float roughness;
    uint albedoTexture;
    uint normalTexture;
};

layout(binding = 3) uniform MaterialGlobalData {
    MaterialGlobal materialGlobal;
} materialGlobalData;

layout(binding = 4) uniform MaterialInstanceData {
    MaterialInstance materialInstace;
} materialInstanceData;