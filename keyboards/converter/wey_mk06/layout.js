let qmk_map = " \
#define LAYOUT( \
    K90, K91, K92, K93, K80, K81, K82, K83, K84, K85, K86, K87, K88, K89, K8A, K8B, KA0, KA1, KA2, KA3, \
    K94, K95, K96, K97, KA4, KA5, KA6, KA7, \
    K98, K99, K9A, K9B, KA8, KA9, KAA, KAB, \
    K9C, K9D, K9E, K9F, KAC, KAD, KAE, KAF, \
    K6E, K70, K71, K72, K73, K74, K75, K76, K77, K78, K79, K7A, K7B, \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0F, K7C, K7D, K7E, K5A, K5F, K64, K69, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K2B, K4B, K50, K55, K5B, K60, K65, K6A, \
    K1E, K1F, K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K4C, K51, K56, K5C, K61, K66, \
    K2C, K2D, K2E, K2F, K30, K31, K32, K33, K34, K35, K36, K37, K39, K4E, K53, K58, K5D, K62, K67, K6C, \
    K3A, K3B, K3C, K3D, K3E, K3F, K41, K40, K4F, K54, K59, K63, K68) { \
    { KC_NO, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, KC_NO, K0F }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, KC_NO, K1E, K1F }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, KC_NO, K39, K3A, K3B, K3C, K3D, K3E, K3F }, \
    { K40, K41, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, K4B, K4C, KC_NO, K4E, K4F }, \
    { K50, K51, KC_NO, K53, K54, K55, K56, KC_NO, K58, K59, K5A, K5B, K5C, K5D, KC_NO, K5F }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69, K6A, KC_NO, K6C, KC_NO, K6E, KC_NO }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, K79, K7A, K7B, K7C, K7D, K7E, KC_NO }, \
    { K80, K81, K82, K83, K84, K85, K86, K87, K88, K89, K8A, K8B, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { K90, K91, K92, K93, K94, K95, K96, K97, K98, K99, K9A, K9B, K9C, K9D, K9E, K9F }, \
    { KA0, KA1, KA2, KA3, KA4, KA5, KA6, KA7, KA8, KA9, KAA, KAB, KAC, KAD, KAE, KAF }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
    { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO } \
}";

let layout = qmk_map.substring(qmk_map.indexOf("(")+1,qmk_map.indexOf(")")).split("     ");
let mapping = qmk_map.substring(qmk_map.indexOf(") {")+1,qmk_map.lastIndexOf("}")).split("     ");
let idx = 0;
for (let line of layout) {
    layout[idx] = line.replaceAll(" ", "").replace(/,*$/, '').trim().split(",")
    idx++;
}
layout.shift();

idx = 0;
for (let line of mapping) {
    mapping[idx] = line.replaceAll(" ", "").replaceAll("{", "").replaceAll("}", "").replace(/,*$/, '').trim().split(",");
    idx++
}
mapping.shift();

for (let line of layout) {
    for (let value of line) {
        // console.log(value);
        for (let x in mapping) {
            for (let y in mapping[x]) {
                if (mapping[x][y] === value) {
                    console.log(`${value}: ${x},${y}`);
                }
            }
        }
    }
    console.log("\n")
}

// console.log(mapping);
