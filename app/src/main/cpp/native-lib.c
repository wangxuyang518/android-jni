#include <jni.h>
#include <string.h>



JNIEXPORT jstring

JNICALL
Java_com_example_wxy_jnitest_MainActivity_stringFromJNI(JNIEnv *env, jobject jobject1) {
    char *cstr = "stringFromJNI";
    jstring jstr1 = (*env)->NewStringUTF(env, cstr);

    return jstr1;
}

JNIEXPORT jstring

JNICALL
stringFromJNI2(JNIEnv *env, jobject jobject1) {
    char *cstr = "调用java方法";
    jclass clz = (*env)->FindClass(env,"com/example/wxy/jnitest/MainActivity");
    jmethodID jmethodID1=(*env)->GetMethodID(env,clz,"getString","()Ljava/lang/String");
    jstring  cs =(*env)->CallObjectMethod(env, clz, jmethodID1);

    return cs;
}


JNIEXPORT jstring JNICALL
stringFromJNI1Test(JNIEnv *env, jobject instance) {

    char *cstr = "stringFromJNI1";
    return  (*env)->NewStringUTF(env,cstr);
}
static JNINativeMethod methods[]={

        {
                "stringFromJNI1",
                "()Ljava/lang/String;",
                (jstring)stringFromJNI1Test
        },
        {
                "stringFromJNI2",
                "()Ljava/lang/String;",
                (jstring)stringFromJNI2
        }
};


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *jvm, void *reserved){
    JNIEnv *env;

    jint i=(*jvm)->GetEnv(jvm,(void**) &env, JNI_VERSION_1_4);
    if(i!= JNI_OK){
        return -1;
    }
    jclass clz = (*env)->FindClass(env,"com/example/wxy/jnitest/MainActivity");
    (*env)->RegisterNatives(env,clz,methods,sizeof(methods)/sizeof(methods[0]));
    return JNI_VERSION_1_4;
}
