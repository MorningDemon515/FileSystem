#ifdef __cplusplus
extern "C" {
#endif

int GetINIint(const char* file, const char* section, const char* key);
float GetINIfloat(const char* file, const char* section, const char* key);
const char* GetINIstring(const char* file, const char* section, const char* key);

void WriteINIint(const char* file, const char* section, const char* key, int value);
void WriteINIfloat(const char* file, const char* section, const char* key, float value);
void WriteINIstring(const char* file, const char* section, const char* key, const char* value);

int GetJSONint(const char* file, const char* key);
float GetJSONfloat(const char* file, const char* key);
const char* GetJSONstring(const char* file, const char* key);

void WriteJSONint(const char* file, const char* key, int value);
void WriteJSONfloat(const char* file, const char* key, float value);
void WriteJSONstring(const char* file, const char* key, const char* value);

#ifdef __cplusplus
}
#endif