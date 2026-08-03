#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // 1. Inicializar GLFW
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Configurar OpenGL 3.0
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Crear la ventana
    GLFWwindow* window = glfwCreateWindow(1280, 800, "Mi Aplicacion ImGui", nullptr, nullptr);
    if (window == nullptr)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Activar VSync

    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (mode != nullptr) {
        int window_x = (mode->width - 1280) / 2;
        int window_y = (mode->height - 800) / 2;
        glfwSetWindowPos(window, window_x, window_y);
    }

    // 2. Inicializar el contexto de Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Permitir control con teclado

    // Configurar el estilo (puedes cambiar a ImGui::StyleColorsLight())
    ImGui::StyleColorsDark();

    // Inicializar los backends de renderizado
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Color de fondo de la ventana principal
    ImVec4 clear_color = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);

    // 3. Bucle Principal
    while (!glfwWindowShouldClose(window))
    {
        // Procesar eventos del sistema
        glfwPollEvents();
        if (glfwGetWindowAttrib(window, GLFW_ICONIFIED) != 0)
        {
            ImGui_ImplGlfw_Sleep(10);
            continue;
        }

        // Iniciar un nuevo fotograma (frame) de ImGui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ============================================================
        // AQUI COMIENZAS A CONSTRUIR TU INTERFAZ
        // ============================================================

        ImGui::Begin("Panel Principal");
        ImGui::Text("¡Hola, esta es una ventana limpia!");
        ImGui::End();

        // ============================================================

        // 4. Renderizado
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);

        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    // 5. Limpieza y cierre
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}