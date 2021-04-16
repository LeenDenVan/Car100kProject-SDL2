#include "init.h"

PyObject* pModule = NULL;

GLuint gProgID = 0;
GLint gVertexPos2DLoc = -1;
GLuint gVBO = 0;
GLuint gIBO = 0;

bool initPython() {
	Py_Initialize();
	if (!Py_IsInitialized()) {
		printf("Error: Unable to initialize python module.\n");
		return false;
	}
	printf("Python module has initialized successfully.");
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./src/pythonscripts')");
	return true;
}

PyObject* initScript(const char* scriptName) {
	PyObject* temp = NULL;
	temp = PyImport_ImportModule(scriptName);
	if (temp == NULL) {
		printf("Error: Unable to load script:%s\n", scriptName);
		return NULL;
	}
	else {
		return temp;
	}
}

bool callFunctionWithNoArg(PyObject* scriptName, const char* function) {
	PyObject* temp = NULL;
	temp = PyObject_GetAttrString(scriptName, function);
	if (temp == NULL) {
		printf("Error: Couldn't find expected function:%s\n", scriptName);
		return false;
	}
	else {
		PyObject_CallObject(temp, NULL);
		return true;
	}
}

bool closePython() {
	Py_Finalize();
	return true;
}

bool init() {

    bool success = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        success = false;
    }
    else {

        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {

        }

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

        window = SDL_CreateWindow("Car100k Project", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SWID, SHEIG, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            success = false;
        }
        else {

            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (renderer == NULL) {
                success = false;
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) & imgFlags)) {
                    success = false;
                }

                if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                    success = false;
                }

                //Initialize SDL_ttf
                if (TTF_Init() == -1)
                {
                    printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
                    success = false;
                }
            }
        }
    }

    if (!initPython()) {
        printf("Warning: Unable to initialize python.\n");
    }
    else {
        pModule = initScript("hellosdl");
    }

    return success;

}

void close() {

    SDL_DestroyWindow(window);
    window = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;

    SDL_DestroyTexture(player);
    player = NULL;

    closePython();

    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

/*bool initGL() {
    //Success flag
    bool success = true;

    //Generate program
    gProgID = glCreateProgram();

    //Create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

    //Get vertex source
    const GLchar* vertexShaderSource[] =
    {
        "#version 140\nin vec2 LVertexPos2D; void main() { gl_Position = vec4( LVertexPos2D.x, LVertexPos2D.y, 0, 1 ); }"
    };

    //Set vertex source
    glShaderSource(vertexShader, 1, vertexShaderSource, NULL);

    //Compile vertex source
    glCompileShader(vertexShader);

    //Check vertex shader for errors
    GLint vShaderCompiled = GL_FALSE;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &vShaderCompiled);
    if (vShaderCompiled != GL_TRUE)
    {
        printf("Unable to compile vertex shader %d!\n", vertexShader);
        printShaderLog(vertexShader);
        success = false;
    }else{
        //Attach vertex shader to program
        glAttachShader(gProgID, vertexShader);


        //Create fragment shader
        GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

        //Get fragment source
        const GLchar* fragmentShaderSource[] =
        {
            "#version 140\nout vec4 LFragment; void main() { LFragment = vec4( 1.0, 1.0, 1.0, 1.0 ); }"
        };

        //Set fragment source
        glShaderSource(fragmentShader, 1, fragmentShaderSource, NULL);

        //Compile fragment source
        glCompileShader(fragmentShader);

        //Check fragment shader for errors
        GLint fShaderCompiled = GL_FALSE;
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled);
        if (fShaderCompiled != GL_TRUE)
        {
            printf("Unable to compile fragment shader %d!\n", fragmentShader);
            printShaderLog(fragmentShader);
            success = false;
        }
        else
        {
            //Attach fragment shader to program
            glAttachShader(gProgID, fragmentShader);


            //Link program
            glLinkProgram(gProgID);

            //Check for errors
            GLint programSuccess = GL_TRUE;
            glGetProgramiv(gProgID, GL_LINK_STATUS, &programSuccess);
            if (programSuccess != GL_TRUE)
            {
                printf("Error linking program %d!\n", gProgID);
                printProgramLog(gProgID);
                success = false;
            }
            else
            {
                //Get vertex attribute location
                gVertexPos2DLoc = glGetAttribLocation(gProgID, "LVertexPos2D");
                if (gVertexPos2DLoc == -1)
                {
                    printf("LVertexPos2D is not a valid glsl program variable!\n");
                    success = false;
                }
                else
                {
                    //Initialize clear color
                    glClearColor(0.f, 0.f, 0.f, 1.f);

                    //VBO data
                    GLfloat vertexData[] =
                    {
                        -0.5f, -0.5f,
                         0.5f, -0.5f,
                         0.5f,  0.5f,
                        -0.5f,  0.5f
                    };

                    //IBO data
                    GLuint indexData[] = { 0, 1, 2, 3 };

                    //Create VBO
                    glGenBuffers(1, &gVBO);
                    glBindBuffer(GL_ARRAY_BUFFER, gVBO);
                    glBufferData(GL_ARRAY_BUFFER, 2 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

                    //Create IBO
                    glGenBuffers(1, &gIBO);
                    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
                    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW);
                }
            }
        }
    }
    return success;
}

void printProgramLog(GLuint program)
{
    //Make sure name is shader
    if (glIsProgram(program))
    {
        //Program log length
        int infoLogLength = 0;
        int maxLength = infoLogLength;

        //Get info string length
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

        //Allocate string
        char* infoLog = new char[maxLength];

        //Get info log
        glGetProgramInfoLog(program, maxLength, &infoLogLength, infoLog);
        if (infoLogLength > 0)
        {
            //Print Log
            printf("%s\n", infoLog);
        }

        //Deallocate string
        delete[] infoLog;
    }
    else
    {
        printf("Name %d is not a program\n", program);
    }
}

void printShaderLog(GLuint shader)
{
    //Make sure name is shader
    if (glIsShader(shader))
    {
        //Shader log length
        int infoLogLength = 0;
        int maxLength = infoLogLength;

        //Get info string length
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        //Allocate string
        char* infoLog = new char[maxLength];

        //Get info log
        glGetShaderInfoLog(shader, maxLength, &infoLogLength, infoLog);
        if (infoLogLength > 0)
        {
            //Print Log
            printf("%s\n", infoLog);
        }

        //Deallocate string
        delete[] infoLog;
    }
    else
    {
        printf("Name %d is not a shader\n", shader);
    }
}
*/