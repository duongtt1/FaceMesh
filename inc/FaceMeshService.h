#ifndef FACEMESHSERVICE_H
#define FACEMESHSERVICE_H

#include <opencv2/core/core.hpp>

#include <ncnn/net.h>

#define THRESGOLD 2.5

struct FaceObjectMesh
{
    cv::Rect_<float> rect;
    cv::Point2f landmark[5];
    float prob;
};

enum ORIENTATION_t
{
    ORIENTATION_INVALID     =   -1,
    ORIENTATION_STRAIGHT    = 0,
    ORIENTATION_LEFT        = 1,
    ORIENTATION_RIGHT       = 2,
};

class FaceMeshService
{
public:
    FaceMeshService();
    ~FaceMeshService();
    int load(const char *modeltype);

    int detect(const cv::Mat &rgb, std::vector<FaceObjectMesh> &faceobjects, float prob_threshold = 0.5f, float nms_threshold = 0.45f);

    int draw(cv::Mat &rgb, const std::vector<FaceObjectMesh> &faceobjects);
    void seg(cv::Mat &rgb, const FaceObjectMesh &obj, cv::Mat &mask, cv::Rect &box);
    void landmark(cv::Mat &rgb, const FaceObjectMesh &obj, std::vector<cv::Point2f> &landmarks);

    ORIENTATION_t detectFacialOrientation(const cv::Mat &img);

    static FaceMeshService* getInstance();

private:
    const float meanVals[3] = {123.675f, 116.28f, 103.53f};
    const float normVals[3] = {0.01712475f, 0.0175f, 0.01742919f};
    ncnn::Net facept;
    ncnn::Net faceseg;
    ncnn::Net scrfd;
    bool has_kps = false;
    
    FaceMeshService(FaceMeshService const&) = delete;
    void operator=(FaceMeshService const&) = delete;

    static FaceMeshService* m_instance;
    static std::mutex m_ctx;

};

#endif // FACEMESHSERVICE_H
