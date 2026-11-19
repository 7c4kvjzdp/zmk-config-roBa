/*
 * 起動時に JIS 読み替えマップ（keymap の jis_map）を有効にする。
 * zmk-layout-shift のマップは初期状態が無効で、通常は &tog_ls 系のキーで
 * 有効化するが、このキーボードでは切り替えキーを置かずに常に有効にする。
 */
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/init.h>
#include <errno.h>
#include <stdbool.h>

#if DT_NODE_EXISTS(DT_NODELABEL(jis_map))

/* zmk-layout-shift/src/layout_shift_map.h */
void layout_shift_map_set_active(const struct device *dev, bool active);

static int jis_default_on_init(void) {
    const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(jis_map));

    if (!device_is_ready(dev)) {
        return -ENODEV;
    }
    layout_shift_map_set_active(dev, true);
    return 0;
}

SYS_INIT(jis_default_on_init, APPLICATION, 99);

#endif
