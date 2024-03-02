#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>

#define BAD 0
#define NUM 1
#define NAV 2
#define SYM 3
#define FUN 4

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};

/ {
    macros {
        macro_sch: macro_sch {
            label = "Macro_sch";
            compatible = "zmk,behavior-macro";
            #binding-cells = <0>;
            bindings = <
		    &macro_tap &kp S
		    &macro_release &kp RSHIFT
		    &macro_tap &kp C &kp H
	    >;
        };
    };
};


#define COMBO(NAME, BINDINGS, KEYPOS) \
combo_##NAME { \
    timeout-ms = <20>; \
    bindings = <BINDINGS>; \
    key-positions = <KEYPOS>; \
};

//   00  01  02  03  04  05  06  07  08  09
//  10  11  12  13  14    15  16  17  18  19
// 20  21  22  23  24  25  26  27  28  29  30
//--------------------------------------------
//   00   w   f   p   b   j   l   u   y  09
//   r   s   t   h   k     x   n   a   i   o
// 20   c   g   d  SPC 25   e   m   ,   .   /

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(sch, &macro_sch, 1 3)
        COMBO(slash, &kp SLASH, 28 29)
        COMBO(dash, &kp MINUS, 27 28)
        COMBO(enter, &kp ENTER, 27 29)
        COMBO(esc, &kp ESC, 22 23)
/* parentheticals */
        COMBO(lbrc, &kp LBRC, 1 11)
        COMBO(lbkt, &kp LBKT, 2 12)
        COMBO(lpar, &kp LPAR, 3 13)
        COMBO(lt, &kp LT, 4 14)
        COMBO(gt, &kp GT, 5 15)
        COMBO(rpar, &kp RPAR, 6 16)
        COMBO(rbkt, &kp RBKT, 7 17)
        COMBO(rbrc, &kp RBRC, 8 18)
/* caps */
        COMBO(caps, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 1 8)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(delword, &kp LC(BSPC), 6 8)
    };
};

//   00  01  02  03  04  05  06  07  08  09
//  10  11  12  13  14    15  16  17  18  19
// 20  21  22  23  24  25  26  27  28  29  30

/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 25 26 27 28 29 30>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 23 24 25>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <100>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            // hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
