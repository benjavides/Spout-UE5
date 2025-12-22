# SpoutPlugin (UE5)

Windows-only Unreal Engine 5 plugin that sends and receives textures via Spout using a DX11-on-DX12 bridge.

## Introduction
This plugin started from a real production need rather than as a polished, ready-made solution.
While working with Unreal Engine 5, I noticed there were very few practical and up-to-date ways to integrate UE with other real-time tools such as TouchDesigner, especially when dealing with modern DX12 workflows.

So I decided to build my own solution. I strongly believe in the idea that sharing is caring, which is why I did not start entirely from scratch. Instead, I forked an existing open-source repository and focused on making it work again across multiple Unreal Engine 5 versions, adapting it to current engine constraints and workflows.

Although I am comfortable working with C++, DirectX 11, and DirectX 12, this tool was developed primarily from the perspective of an artist and technical user rather than a traditional software engineer. The focus is therefore on solving real workflow problems and enabling practical integration, rather than building a perfectly abstracted or enterprise-grade system.

The goal of this project is to provide a clear and debuggable bridge between Unreal Engine and Spout, without hiding complexity, especially when dealing with DX11-on-DX12 interop and GPU resource sharing.

This plugin should not be considered fully production-ready. However, depending on your use case and with enough testing, it can be reliable enough. At least, it has been for my own projects.

I also started developing this plugin with future integration into generative AI workflows in mind.

Thanks to zuyi53, the original author of the repository this work is based on: [[link](https://github.com/zuyi53/Spout-UE5)].
If you find bugs or issues, please report them.
If you need a production-ready, paid solution with more features beyond Spout, consider the Off World Live plugin: [[link](https://offworld.live/)].

## Features

- **Spout Sender**
  - Send textures to external applications either from the **game viewport** or from a `UTextureRenderTarget2D`
  - Automatic creation and update of the Spout sender stream

- **Spout Receiver**
  - Receive Spout streams into a transient `UTexture2D`
  - Optional output to a user-provided `UTextureRenderTarget2D`
  - Provides a dynamic material instance ready to be applied to meshes

- **Rendering and Interop**
  - D3D11-on-DX12 interoperability layer built on top of Unreal Engine 5’s D3D12 RHI
  - GPU-based texture sharing via Spout, without disk or network transfer

## Requirements
- Windows 64-bit
- Unreal Engine 5 with D3D12 RHI enabled (Spout requires D3D11 interop)
- Spout runtime (bundled `Spout.dll` and `Spout.lib` under `ThirdParty/Spout`)

## Build

This plugin is intended to be built as part of a **project**, not as an engine plugin.

### Supported Unreal Engine versions
- **Tested on Unreal Engine 5.3 and newer**
- UE 5.1 and 5.2 may work but are not actively supported

### Build steps

1. Copy the `SpoutPlugin` folder into your project’s `Plugins/` directory.
2. Make sure the plugin is enabled in your project settings.
3. Ensure your project is using the **D3D12 RHI** (required).
4. Generate project files if needed.
5. Build the project using your IDE or Unreal Editor.

The bundled `Spout.dll` will be staged automatically into your project’s `Binaries/Win64` directory during the build process.

### Notes

- This plugin is **Windows-only**.
- A working C++ toolchain is required (Visual Studio with the appropriate Windows SDK).
- If you encounter build errors after upgrading Unreal Engine versions, try cleaning the project and regenerating project files.

## Installation
1. Download the plugin for your Unreal Engine version from the [Releases](../../releases) page if you do not wish to build it yourself.
2. Copy the `SpoutPlugin` folder into your project `Plugins/` directory.
3. Ensure the plugin is enabled in your project.


## Usage

> The plugin includes ready-to-use **example Blueprints** under the plugin `Content/` folder, which can be used to quickly test both Sender and Receiver setups without writing any code.

### Sender

- Call `USpoutBPFunctionLibrary::SpoutSender` every frame (Tick) or on a timer.
- Set a **Spout Name**, which uniquely identifies the stream and must match the receiver.
- Choose what to send using **Send Texture From**:
  - `GameViewport` – sends the active game viewport (backbuffer).
  - `TextureRenderTarget2D` – sends the contents of a specified render target.
- When using `TextureRenderTarget2D`, ensure the render target asset is valid and updated.
- The sender automatically creates and updates the Spout stream while it is being called.

#### SceneCapture2D and Render Target Notes

When using a `TextureRenderTarget2D` as the source for the Sender, a common setup is to drive it using a `SceneCapture2D`, as shown in the example Blueprints included with the plugin.

In this case, the `SceneCapture2D` **Capture Source** must be set to:

- **`FinalColor (LDR)`**

and **not** to `SceneColor (HDR) in RGB`.

If `SceneColor (HDR)` is used, the texture sent through Spout may appear **black** on the receiving application.

At the moment, this limitation is still under investigation. A proper fix or improvement will be added in a future update if possible.  
If you have suggestions or insights on how to handle this correctly, contributions and advice are very welcome.

Once the Capture Source is set correctly, the `Texture Target` of the `SceneCapture2D` can be safely used as the input Render Target for the Spout Sender.

**Notes**
- Only one sender can own a given Spout Name at a time.
- The sender must be called continuously to keep the stream alive.
- This workflow is Windows-only and relies on DX11-on-DX12 GPU interop.


---

### Receiver

- Call `USpoutBPFunctionLibrary::SpoutReceiver` every frame (Tick) or on a timer.
- The **Spout Name** must exactly match the name used by the sender.
- The function outputs:
  - `OutTexture` – a transient `UTexture2D` updated from the Spout stream.
  - `OutMat` – a dynamic material instance bound to the received texture.
  - Optional `UTextureRenderTarget2D` – the receiver will copy the stream into it.
- Always validate `OutMat` before using it, as the sender may not be available or may reconnect.

**Notes**
- The receiver automatically reconnects when the sender becomes available.
- The assigned material must be compatible with Spout input.
- Avoid heavy logic on Tick; use a timer if possible.



## Content
This plugin ships with sample content under `Content/` when `CanContainContent` is enabled in `SpoutPlugin.uplugin`.

## Notes and Limitations

- This plugin is **Windows-only** and requires Unreal Engine to run with the **D3D12 RHI** enabled.  
  Internally, a D3D11-on-DX12 device is created to support Spout interoperability.

- At the moment, only a **limited set of texture formats** is supported.  
  Support for additional formats is still a work in progress.

- For now, the **recommended and most reliable format** for Render Targets is:  
  **RTF RGBA8 sRGB**

- The Spout Receiver currently performs a **CPU readback** each frame before updating Unreal textures.  
  This can become expensive with large resolutions or high update rates and should be considered when targeting real-time performance.

- The Sender and Receiver must be called **continuously** (Tick or timer) to keep the Spout stream alive and updated.

- Only **one sender per Spout Name** can be active at a time. Multiple senders using the same name will conflict.

- This plugin is **not guaranteed to be production-ready** for shipping products without thorough testing.  
  Stability and performance may vary depending on hardware, drivers, texture sizes, and usage patterns.

- Error handling and recovery are intentionally minimal and designed to favor debuggability over silent failure.

- This plugin is intended primarily for **real-time workflows, prototyping, tools, and experimentation**, rather than long-running unattended deployments.

## Troubleshooting

### No texture received / Receiver outputs invalid material
- Ensure the **Spout Name** exactly matches between Sender and Receiver.
- Verify that the Sender is running and being called continuously (Tick or timer).
- Check that only **one sender** is using the same Spout Name.
- Make sure the Render Target format is supported.  
  The recommended format is **RTF RGBA8 sRGB**.

### Sender does not appear in external applications
- Confirm that the project is running with the **D3D12 RHI** enabled.
- Ensure the Spout runtime is available and that `Spout.dll` is correctly staged in `Binaries/Win64`.
- If sending from the viewport, make sure the game window is actively rendering and not minimized.

### Performance issues or frame drops
- Large textures and high update rates can be expensive, especially on the Receiver side due to CPU readback.
- Reduce resolution or update frequency if possible.
- Prefer timers over Tick when full frame-rate updates are not required.

### Crashes or instability
- Verify GPU drivers are up to date.
- Test with different texture resolutions and formats.
- Avoid changing Render Target resources at runtime while the Sender or Receiver is active.
- If issues persist, reproduce the problem in a minimal project before reporting it.

### Plugin does not compile or load
- Ensure the plugin is placed inside the project `Plugins` directory, not the engine directory.
- Confirm you are using a supported Unreal Engine 5 version.
- Regenerate project files and rebuild after enabling the plugin.


## Third-Party
- Spout: http://spout.zeal.co/

## Attribution and Redistribution

This project is released under the MIT License.

While commercial use is allowed, redistributing this plugin as-is or with minimal changes and selling it as a standalone product goes against the spirit of this project.

If you build something cool with this plugin and feel like sharing it, let me know. I would be happy to consider adding it to a future **Showcase** section.


## License

This project is licensed under the MIT License.  
See the [LICENSE](LICENSE) file for details.
