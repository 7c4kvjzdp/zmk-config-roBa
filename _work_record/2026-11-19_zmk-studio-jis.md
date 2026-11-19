# 2026-11-19 ZMK Studio の JIS 表示版を公開 / ファームの読み替えは見送り

## 経緯
- ファーム側で US→JIS 読み替え（`jis-layout-shift` ブランチ）を作ったが、
  Shift+2 が @ になる（記号配列が US になる）ため不採用。読み替えなしを継続。
  `jis-layout-shift` ブランチは main にマージしない（参考として残置）。
- 代わりに ZMK Studio 本体を改造し、表示を JIS に合わせた版を公開。

## 公開先
- https://7c4kvjzdp.github.io/zmk-studio-jis/
- ソースの差分とビルド手順: 7c4kvjzdp.github.io リポジトリの `zmk-studio-jis/source/`
- ベース: zmkfirmware/zmk-studio 1bb6bb8（v0.3.1）

## 変更点
- 配置図ラベルを JIS で入力される文字に（Shift 付きは Shift 時の文字）
- キー選択の一覧の先頭に JIS の文字（Shift 時の文字）、元の名前を薄く併記。記号で絞り込み可
