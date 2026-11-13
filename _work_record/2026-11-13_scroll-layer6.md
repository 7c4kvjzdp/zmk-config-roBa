# 2026-11-13 レイヤー6でもトラックボールをスクロールにする

- 変更: `config/roBa.keymap` の `&trackball` で `scroll-layers = <5>` → `<5 6>`
- 目的: レイヤー6（右親指外側の Layer-Tap 長押し）中もトラックボールでスクロール
- 反映: roBa_R のファームのみ書き込みでよい（トラックボールは右手側）
- 注意: キーボード本体の配置は ZMK Studio で保存したものが優先され、リポジトリの keymap とは別物。
  Studio の配置はファーム書き込みでは消えない（settings_reset / Restore Stock Settings で消える）
