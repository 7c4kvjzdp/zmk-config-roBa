# 2026-11-19 日本語配列（JIS）用の読み替えを組み込む

ブランチ: `jis-layout-shift`（`scroll-on-layer6` から分岐）

## 方針
- 自作ではなく kot149/zmk-layout-shift（MIT、ZMK v0.3 でもテストあり）を組み込む
- `&kp` を差し替えるので Studio で割り当てたキーにも読み替えが効く
- 半角/全角（GRAVE）は読み替え対象から外す（ユーザー選択）
- 切り替えキーは置かず常に有効（ユーザー選択）

## 変更
- `config/west.yml`: zmk-layout-shift を追加（v2 の f9ea030 に固定）
- `config/roBa.keymap`:
  - `layout_shift_kp_override.dtsi` を include
  - `&kp` の label を削除（Studio 保存済み割り当てはデバイス名 "key_press" で参照しているため、名前を変えない）
  - `kpls` / `mtls` を削除（key press ドライバが instance 0 しか作らないため実体を 1 つに）
  - GRAVE を除いた独自マップ `jis_map`
- `src/jis_default_on.c` + ルート `CMakeLists.txt` + `zephyr/module.yml` に `cmake: .`:
  起動時に jis_map を有効化（モジュールの初期状態は無効のため）
- `roBa_R.conf`: `CONFIG_LAYOUT_SHIFT_PERSISTENT_STATE=n`

## 注意
- 読み替え表を見て JIS 用に選んだ Studio のキー（@ のつもりで `[` など）は二重に読み替わるので選び直す
- 書き込むのは roBa_R のみ
