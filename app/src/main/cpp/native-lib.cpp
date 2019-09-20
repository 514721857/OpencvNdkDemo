#include <jni.h>
#include <string>
#include <opencv2/core/hal/interface.h>
#include <opencv2/calib3d.hpp>
using namespace cv;

extern "C" JNIEXPORT jintArray JNICALL
Java_com_sgr_opencvndkdemo_MainActivity_Bitmap2Grey(JNIEnv *env, jobject, jintArray buf, int w, int h){
    jint *pixels = env->GetIntArrayElements(buf, NULL);
    if(pixels == NULL){
        return NULL;
    }

    cv::Mat imgData(h, w,CV_8UC4, pixels);
    uchar *ptr = imgData.ptr(0);
    for(int i=0; i<w*h; i++){
        int grayScale = (int)(ptr[4*i+2]*0.299 + ptr[4*i+1]*0.587 + ptr[4*i+0]*0.114);
        ptr[4*i+0] = (uchar)grayScale;
        ptr[4*i+1] = (uchar)grayScale;
        ptr[4*i+2] = (uchar)grayScale;
    }
    int size = w * h;
    jintArray result = env->NewIntArray(size);
    env->SetIntArrayRegion(result, 0, size, pixels);
    env->ReleaseIntArrayElements(buf, pixels, 0);
    return result;
}

