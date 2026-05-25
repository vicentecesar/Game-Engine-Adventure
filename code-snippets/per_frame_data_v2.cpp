#define MAX_SHADOW_MAPS 4

typedef struct PerFrameData {
    Matrix4f projectionView;
    Matrix4f inverseLightProjectionView[MAX_SHADOW_MAPS];
    Vector4f cameraPosition;
    float32 time;
    int32 shadowMapCount;
} PerFrameData;