typedef enum class MaterialGPUType
{
    /*
    =======================================================
    INTEGER
    =======================================================
    */

    Int,
    IVec2,
    IVec3,
    IVec4,

    UInt,
    UVec2,
    UVec3,
    UVec4,
    
    /*
    =======================================================
    FLOATING POINT
    =======================================================
    */

    Float,
    Vec2,
    Vec3,
    Vec4,

    Double,
    DVec2,
    DVec3,
    DVec4,

    /*
    =======================================================
    BOOLEAN
    =======================================================
    */

    Bool,
    BVec2,
    BVec3,
    BVec4,

    /*
    =======================================================
    MATRICES
    =======================================================
    */

    Mat2,
    Mat3,
    Mat4,

    Mat2x3,
    Mat2x4,

    Mat3x2,
    Mat3x4,

    Mat4x2,
    Mat4x3,

    /*
    =======================================================
    TEXTURES
    =======================================================
    */

    Sampler1D,
    Sampler2D,
    Sampler3D,

    SamplerCube,

    Sampler2DArray,
    SamplerCubeArray,

    Sampler2DShadow,
    SamplerCubeShadow,

    /*
    =======================================================
    STORAGE IMAGES
    =======================================================
    */

    Image1D,
    Image2D,
    Image3D,

    ImageCube,

    /*
    =======================================================
    BUFFER TYPES
    =======================================================
    */

    UniformBuffer,
    StorageBuffer,

    /*
    =======================================================
    RAYTRACING
    =======================================================
    */

    AccelerationStructure,

    /*
    =======================================================
    SPECIAL
    =======================================================
    */

    Struct,
    Array,

    Unknown

} MaterialGPUType;

/* Dado um tipo de campo de material na GPU, obtenha seu tamanho em bytes do lado da CPU */
uint32 drvMaterial_GetSize(MaterialGPUType materialGPUType);