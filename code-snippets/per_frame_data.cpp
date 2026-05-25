typedef struct PerFrameData {
    Matrix4f projectionView;
    Matrix4f inverseLightProjectionView;
    Vector4f cameraPosition;
    float32 time;
} PerFrameData;