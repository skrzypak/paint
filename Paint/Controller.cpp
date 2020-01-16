#include "Controller.h"
#include <shlobj.h>

Controller::Controller(sf::RenderWindow* w, tgui::Gui* g): __activeShape(new Controller::Type<DEFAULT_MODE>), __activeProperites(new ShapeProperities), __canvas(new Canvas)
{
#ifdef _DEBUG
	std::cout << "Controller::Controller(sf::RenderWindow* w,  tgui::Gui* g): __shape(new Controller::Type<DEFAULT_MODE>), __properites(new Controller::ShapeProperities), __canvas(new Canvas)" << std::endl;
#endif 
	__window = w;
	__gui = g;
};

Controller::~Controller()
{
#ifdef _DEBUG
	std::cout << "Controller::~Controller()" << std::endl;
#endif 
	delete __activeShape;
	delete __activeProperites;
	delete __canvas;
	__activeShape = nullptr;
	__activeProperites = nullptr;
	__canvas = nullptr;
	__window = nullptr;
	__gui = nullptr;
};

Controller::Shape* Controller::getShapeController()
{
#ifdef _DEBUG
	std::cout << "Controller::Shape* Controller::getShapeController() " << std::endl;
#endif 
	return __activeShape;
};

ShapeProperities* Controller::getShapeProperites()
{
#ifdef _DEBUG
	std::cout << "Controller::Color Controller::getShapeProperites()" << std::endl;
#endif 
	return __activeProperites;
}

Canvas* Controller::getActiveCanvas()
{
#ifdef _DEBUG
	std::cout << "Canvas* Controller::getActiveCanvas()" << std::endl;
#endif 
	return __canvas;
}

void Controller::setFillColor(sf::Color c)
{
#ifdef _DEBUG
	std::cout << "void Controller::setFillColor(sf::Color c)" << std::endl;
#endif 
	__activeProperites->primaryColor = c;
};

void Controller::setOutlineColor(sf::Color c)
{
#ifdef _DEBUG
	std::cout << "void Controller::setOutlineColor(sf::Color c)" << std::endl;
#endif
	__activeProperites->secondaryColor = c;
}

void Controller::setOutlineSize(float s)
{
#ifdef _DEBUG
	std::cout << "void Controller::setOutlineSize(float s)" << std::endl;
#endif
	__activeProperites->outlineSize = s;
}

void Controller::reverseColors()
{
#ifdef _DEBUG
	std::cout << "void Controller::reverseColors()" << std::endl;
#endif
	auto tmp = __activeProperites->primaryColor;
	__activeProperites->primaryColor = __activeProperites->secondaryColor;
	__activeProperites->secondaryColor = tmp;
}

void Controller::setTexture(std::string path)
{
#ifdef _DEBUG
	std::cout << "void Controller::setTexture(std::string path)" << std::endl;
#endif
	__activeProperites->texture->loadFromFile(path);
	__activeProperites->texture->setSmooth(true);
}

void Controller::clearTexture()
{
#ifdef _DEBUG
	std::cout << "void Controller::clearTexture()" << std::endl;
#endif
	delete __activeProperites->texture;
	__activeProperites->texture = new sf::Texture;
}

void Controller::refreshView(sf::RenderWindow* w, tgui::Gui* g)
{
#ifdef _DEBUG
	std::cout << "void Controller::refreshView(sf::RenderWindow* w, tgui::Gui* g)" << std::endl;
#endif
	__canvas->refresh(w, g);
}

void Controller::refreshView()
{
#ifdef _DEBUG
	std::cout << "void Controller::refreshView()" << std::endl;
#endif
	__canvas->refresh(__window, __gui);
}

void Controller::resetCanvas()
{
#ifdef _DEBUG
	std::cout << "void Controller::resetCanvas()" << std::endl;
#endif
	delete __canvas;
	__canvas = new Canvas;
}

void Controller::saveToFile()
{
#ifdef _DEBUG
	std::cout << "void Controller::saveToFile()" << std::endl;
#endif

	CHAR userPicturePath[MAX_PATH];
	SHGetFolderPath(NULL, CSIDL_MYPICTURES, NULL, SHGFP_TYPE_CURRENT, userPicturePath);
	std::string path = static_cast<std::string>(userPicturePath) + "\\file_name";

	unsigned btnWidth = 60, btnNum = 3, btnMargin = 10;

	auto input = tgui::EditBox::create();
	input->setPosition({ 10, 45 });
	input->setSize({ __window->getSize().x - btnWidth * btnNum - btnMargin * btnNum, 25 });
	input->setText(path);

	auto comboExt = tgui::ComboBox::create();
	comboExt->setSize(btnWidth, 25);
	comboExt->setPosition(__window->getSize().x - btnWidth * btnNum - btnMargin * btnNum, 45);
	comboExt->addItem(".jpg");
	comboExt->addItem(".png");
	comboExt->addItem(".bmp");
	comboExt->setSelectedItem(".jpg");
	btnNum--;

	auto btnSave = tgui::Button::create();
	btnSave->setPosition(__window->getSize().x - btnWidth * btnNum - btnMargin * btnNum, 45);
	btnSave->setText("Save");
	btnSave->setSize(btnWidth, 25);
	btnNum--;
	
	auto btnCancel = tgui::Button::create();
	btnCancel->setPosition(__window->getSize().x - btnWidth * btnNum - btnMargin * btnNum, 45);
	btnCancel->setText("Cancel");
	btnCancel->setSize(btnWidth, 25);

	__gui->get("MainMenu")->setEnabled(false);

	auto restoreView = [=]() {
		__gui->remove(__gui->get("Controller::saveToFile()::input"));
		__gui->remove(__gui->get("Controller::saveToFile()::comboExt"));
		__gui->remove(__gui->get("Controller::saveToFile()::btnSave"));
		__gui->remove(__gui->get("Controller::saveToFile()::btnCancel"));
		__gui->get("MainMenu")->setEnabled(true);
	};

	btnSave->connect("pressed", [=]() {
		auto path = input->getText() + comboExt->getSelectedItem();
		try {
			__canvas->saveToImage(__window, path);
			restoreView();
		}
		catch (const std::exception&) {
			restoreView();
		}
	});

	btnCancel->connect("pressed", restoreView);
	
	__gui->add(input, "Controller::saveToFile()::input");
	__gui->add(comboExt, "Controller::saveToFile()::comboExt");
	__gui->add(btnSave, "Controller::saveToFile()::btnSave");
	__gui->add(btnCancel, "Controller::saveToFile()::btnCancel");
}

void Controller::removeLastShape()
{
#ifdef _DEBUG
	std::cout << "void Controller::removeLastShape()" << std::endl;
#endif
	//__canvas->removeLast();
	//(*__canvas)--;
	--(*__canvas);
}
