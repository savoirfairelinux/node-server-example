#include <assert.h>
#include <node_api.h>

napi_value say_hello(napi_env env, napi_callback_info info)
{
	napi_status status;
	napi_value hello;

	status = napi_create_string_utf8(env, "hello world", 11, &hello);

	assert(status == napi_ok);

	return hello;
}

napi_value init(napi_env env, napi_value exports)
{
	napi_status status;
	napi_property_descriptor desc[] = {
		{"say_hello", 0, say_hello, 0, 0, 0, napi_default, 0},
	};

	status = napi_define_properties(env, exports, 1, desc);

	assert(status == napi_ok);

	return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, init)
