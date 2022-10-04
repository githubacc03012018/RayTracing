#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include <iostream>
#include "Renderer.h"
#include "Walnut/Image.h"

using namespace Walnut;

class ExampleLayer : public Walnut::Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Render Information");
		ImGui::End();

		ImGui::Begin("Viewport");

		m_ViewPortWidth = ImGui::GetContentRegionAvail().x;
		m_ViewPortHeight = ImGui::GetContentRegionAvail().y;

		if (!m_Image || m_Image->GetHeight() != m_ViewPortHeight || m_Image->GetWidth() != m_ViewPortWidth) {
			m_Image = std::make_shared<Image>(m_ViewPortWidth, m_ViewPortHeight, ImageFormat::RGBA);
			delete[] m_ImageData;

			m_ImageData = new uint32_t[m_ViewPortWidth * m_ViewPortHeight];
		}

		m_Renderer->Render(m_ViewPortWidth, m_ViewPortHeight, m_ImageData);
		m_Image->SetData(m_ImageData);

		if (m_Image) {
			ImGui::Image(m_Image->GetDescriptorSet(), { (float)m_Image->GetWidth(), (float)m_Image->GetHeight() }, ImVec2(0, 1), ImVec2(1, 0));
		}

		ImGui::End();
	}

	ExampleLayer() {
		m_Renderer = new Hybrid::Renderer();
	}


	~ExampleLayer() {
		delete m_Renderer;
	}

public:
	Hybrid::Renderer* m_Renderer;
	int m_ViewPortWidth, m_ViewPortHeight = 0;
private:
	std::shared_ptr<Image> m_Image;
	uint32_t* m_ImageData = nullptr;
};


Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	Walnut::ApplicationSpecification spec;
	spec.Name = "Ray Tracing";

	Walnut::Application* app = new Walnut::Application(spec);
	app->PushLayer<ExampleLayer>();
	app->SetMenubarCallback([app]()
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					app->Close();
				}
				ImGui::EndMenu();
			}
		});
	return app;
}