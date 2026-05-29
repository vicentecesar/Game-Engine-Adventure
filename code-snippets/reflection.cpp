#define MAX_BINDING_LAYOUT_ELEMENTS 16

typedef enum class BindingLayoutStage : uint32 {
	Vertex                  = 0x00000001,
	TessellationControl     = 0x00000002,
	TessellationEvaluation  = 0x00000004,
	Geometry                = 0x00000008,
	Fragment                = 0x00000010,
    Compute                 = 0x00000020
} BindingLayoutStage;

inline BindingLayoutStage operator | (BindingLayoutStage lhs, BindingLayoutStage rhs) {
    return (BindingLayoutStage)(((uint32)lhs) | ((uint32)rhs));
}

inline BindingLayoutStage operator & (BindingLayoutStage lhs, BindingLayoutStage rhs) {
    return (BindingLayoutStage)(((uint32)lhs) & ((uint32)rhs));
}

typedef enum class BindingDataType : uint32 {
	Sampler                 = 0,
	ImageSampler            = 1,
    Image                   = 2,
    StorageImage            = 3,
    UniformTexelBuffer      = 4,
    StorageTexelBuffer      = 5,
    UniformBuffer           = 6,
    StorageBuffer           = 7,
    UniformBufferDynamic    = 8,
    StorageBufferDynamic    = 9,
    InputAttachment         = 10
} BindingDataType;

typedef struct BindingLayoutElement {
    const char *name;
    BindingLayoutStage stage;
    BindingDataType dataType;
    uint32 binding;
    uint32 set;
    uint32 count;
}  BindingLayoutElement;

typedef struct BindingLayout {
    BindingLayoutElement elements[MAX_BINDING_LAYOUT_ELEMENTS];
    uint32 numberOfElements;
} BindingLayout;

typedef enum class MaterialVariableType {
    Float = 0,
    Integer = 1,
    UnsignedInterger = 2,
    Boolean = 3,
    Vector2 = 4,
    Vector3 = 5,
    Vector4 = 6,
    Matrix2 = 7,
    Matrix3 = 8,
    Matrix4 = 9
} MaterialVariableType;

typedef struct MaterialBufferLayout
{
    StaticArray<char[32], 32> name;
    StaticArray<MaterialVariableType, 32> type;
} MaterialBufferLayout;

typedef struct BinaryShader {
    const char *vertexShaderSource;
    const char *geometryShaderSource;
    const char *fragmentShaderSource;

    void *vertexShaderBinary;
    void *geometryShaderBinary;
    void *fragmentShaderBinary;

    int64 vextexShaderBinarySize;
    int64 geometryShaderBinarySize;
    int64 fragmentShaderBinarySize;

    BindingLayout bindingLayout;

    // Uniformbuffers do material enviados pela engine (perFrameData, modelData)
    // ou pelo usuario (materialInstanceData, materialGlobal)
    MaterialBufferLayout perFrameData;
    MaterialBufferLayout modelData;
    MaterialBufferLayout materialInstanceData;
    MaterialBufferLayout materialGlobalData;
} BinaryShader;