#include <a_samp>
#include "json.inc"

main()
{
    // creating the JSON struct
    new JSON_ID:j1;
    j1 = json_create();
    if(j1 == INVALID_JSON_ID)
    {
        // if json > MAX_JSON_ID
        printf("Error: Invalid JSON");
        return 0;
    }

    // integers
    json_add_int(j1, "integer", 3);
    new integer = json_get_int(j1, "integer");
    printf("j1.integer == %d\n", integer);

    // booleans
    json_add_bool(j1, "boolean", true);
    new bool:boolean = json_get_bool(j1, "boolean");
    printf("j1.boolean == %d\n", boolean);

    // strings
    json_add_string(j1, "string", "hello world");
    new string[128];
    json_get_string(j1, "string", string, sizeof string);
    printf("j1.string == %s\n", string);

    // floats
    json_add_float(j1, "float", 3.0);
    new Float:f = json_get_float(j1, "float");
    printf("j1.float == %f\n", f);

    // JSON
    new JSON_ID:j2 = json_create();
    if(j2 == INVALID_JSON_ID)
    {
        // if json > MAX_JSON_ID
        printf("Error: Invalid JSON");
        return 0;
    }

    json_add_int(j2, "integer", 10);
    new integer2 = json_get_int(j2, "integer");
    printf("j2.integer == %d\n", integer2);

    json_add_json(j1, "json", j2);

    new JSON_ID:j3 = json_get_json(j1, "json");
    if(j3 == INVALID_JSON_ID)
    {
        // if json > MAX_JSON_ID
        printf("Error: Invalid JSON");
        return 0;
    }

    new integer3 = json_get_int(j3, "integer");
    printf("j3.integer == %d\n", integer3);

    // cleaning
    json_destroy(j1);
    json_destroy(j2);
    json_destroy(j3);
    return 0;
}