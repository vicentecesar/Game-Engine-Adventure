typedef struct MaterialField
{
    char *name;
    MaterialGPUType type;
    uint32 offset;
} MaterialField;

struct MaterialData {
    DynamicArray<MaterialField> *fields;

    /*
        Array de dados de material. Dado um material, por exemplo o PBR, esse array contem a sequecia de materiais para
        cada malaha. Se o material for definido como:

        struct MaterialInstance {
            vec4 albedo;            // 16 bytes
            float metallic;         // 4 bytes
            float roughness;        // 4 bytes
            uint albedoTexture;     // 4 bytes
            uint normalTexture;     // 4 bytes
        };

        Temos uma estrutura de 32 bytes. Logo, teremos N * 32 bytes alocados em data. e podemos indexar o ponteiro para o
        material desejado como:
            void *materialInstanceData = ((uint8 *)data)[instanceIndex * 32];
        E acessar um campo especifico como:
             void *materialInstanceDataField = ((uint8 *)data)[instanceIndex * 32 + fieldOffset];
    */
    void *data;
    uint32 instanceSize;
    uint32 instaceCount;
}

/*
    As funções a seguir definem os dados possiveis na GPU, por exemplo, quando temos uma textura, temos apenas um indice
    inteiro, então podemos usar drvMaterial_SetInteger ou drvMaterial_SetUnsignedInteger para definilas no material. As
    funções fazer a mesma coisa ja que tudo se resume a um memcpy com o tamanho do dado.

    NOTE: Talvez seja util assinaturas como:
        void drvMaterial_SetInteger(MaterialData *materialData, char *name, int32 value);
*/

void drvMaterial_SetInteger(MaterialData *materialData, uint32 field, int32 value);
void drvMaterial_SetVector2i(MaterialData *materialData, uint32 field, Vector2i &value);
void drvMaterial_SetVector3i(MaterialData *materialData, uint32 field, Vector3i &value);
void drvMaterial_SetVector4i(MaterialData *materialData, uint32 field, Vector4i &value);

void drvMaterial_SetUnsignedInteger(MaterialData *materialData, uint32 field, uint32 value);
void drvMaterial_SetVector2ui(MaterialData *materialData, uint32 field, Vector2ui &value);
void drvMaterial_SetVector3ui(MaterialData *materialData, uint32 field, Vector3ui &value);
void drvMaterial_SetVector4ui(MaterialData *materialData, uint32 field, Vector4ui &value);

void drvMaterial_SetFloat(MaterialData *materialData, uint32 field, float value);
void drvMaterial_SetVector2f(MaterialData *materialData, uint32 field, Vector2f &value);
void drvMaterial_SetVector3f(MaterialData *materialData, uint32 field, Vector3f &value);
void drvMaterial_SetVector4f(MaterialData *materialData, uint32 field, Vector4f &value);

void drvMaterial_SetDouble(MaterialData *materialData, uint32 field, double value);
void drvMaterial_SetVector2d(MaterialData *materialData, uint32 field, Vector2d &value);
void drvMaterial_SetVector3d(MaterialData *materialData, uint32 field, Vector3d &value);
void drvMaterial_SetVector4d(MaterialData *materialData, uint32 field, Vector4d &value);

void drvMaterial_SetBoolean(MaterialData *materialData, uint32 field, bool32 value);
void drvMaterial_SetVector2b(MaterialData *materialData, uint32 field, Vector2b &value);
void drvMaterial_SetVector3b(MaterialData *materialData, uint32 field, Vector3b &value);
void drvMaterial_SetVector4b(MaterialData *materialData, uint32 field, Vector4b &value);

void drvMaterial_SetMatrix2f(MaterialData *materialData, uint32 field, Matrix2f &value);
void drvMaterial_SetMatrix3f(MaterialData *materialData, uint32 field, Matrix3f &value);
void drvMaterial_SetMatrix4f(MaterialData *materialData, uint32 field, Matrix4f &value);

void drvMaterial_SetMatrix2x3f(MaterialData *materialData, uint32 field, Matrix2x3f &value);
void drvMaterial_SetMatrix3x4f(MaterialData *materialData, uint32 field, Matrix3x4f &value);
void drvMaterial_SetMatrix3x2f(MaterialData *materialData, uint32 field, Matrix3x2f &value);
void drvMaterial_SetMatrix3x4f(MaterialData *materialData, uint32 field, Matrix3x4f &value);
void drvMaterial_SetMatrix4x2f(MaterialData *materialData, uint32 field, Matrix4x2f &value);
void drvMaterial_SetMatrix4x3f(MaterialData *materialData, uint32 field, Matrix4x3f &value);