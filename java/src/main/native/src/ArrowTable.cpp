#include <org_cylondata_cylon_arrow_ArrowTable.h>
#include <cstdint>
#include <iostream>
#include "arrow/arrow_builder.hpp"
#include "Utils.hpp"

JNIEXPORT void JNICALL Java_org_cylondata_cylon_arrow_ArrowTable_addColumn
    (JNIEnv *env, jclass clz, jstring table_id, jint data_type, jlong address, jlong size) {
  auto *buffer = reinterpret_cast<int8_t *>(address);
  for (int64_t i = 0; i < size;) {
    int a = int((unsigned char) (buffer[i + 3]) << 24 |
        (unsigned char) (buffer[i + 2]) << 16 |
        (unsigned char) (buffer[i + 1]) << 8 |
        (unsigned char) (buffer[i]));
    std::cout << a << ",";
    i += 4;
  }
  std::cout << std::endl;
}

JNIEXPORT void JNICALL Java_org_cylondata_cylon_arrow_ArrowTable_createTable
    (JNIEnv *env, jclass cls, jstring table_id) {
  cylon::cyarrow::BeginTable(jstr_to_str(env, table_id));
}

JNIEXPORT void JNICALL Java_org_cylondata_cylon_arrow_ArrowTable_addColumn
    (JNIEnv *env, jclass cls, jstring table_id, jstring col_name, jint type_id, jlong address, jlong size) {
  cylon::cyarrow::AddColumn(
      jstr_to_str(env, table_id),
      jstr_to_str(env, col_name),
      type_id,
      address,
      size
  );
}

JNIEXPORT void JNICALL Java_org_cylondata_cylon_arrow_ArrowTable_createTable
    (JNIEnv *env, jclass clz, jstring tab_id, jbyteArray schema_bytes) {
//  std::cout << "Creating table..." << std::endl;
//  auto schema_length = env->GetArrayLength(schema_bytes);
//  auto *schema_buffer = new uint8_t[schema_length];
//  std::cout << "Getting byte array" << std::endl;
//  env->GetByteArrayRegion(schema_bytes, 0, schema_length, reinterpret_cast<jbyte *>(schema_bytes));
//
//  std::cout << "Calling build" << std::endl;
//  cylon::cyarrow::Build("", schema_buffer, schema_length,
//                       std::vector<int8_t *>{}, std::vector<int64_t>{});
//  std::cout << "Ot of  build" << std::endl;
//  delete[] schema_buffer;
}