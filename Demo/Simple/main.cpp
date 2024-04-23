#include <QApplication>
#include <QMainWindow>

#include <QtnProperty/PropertyWidget.h>
#include <QtnProperty/PropertyCore.h>
#include <QtnProperty/GUI/PropertyQColor.h>

class DemoSimpleWindow : public QMainWindow
{
public:
	DemoSimpleWindow()
	{
		QtnPropertyWidget *qtnP = new QtnPropertyWidget(this);
		QtnPropertySet *m_propertySet = new QtnPropertySet(this);

		auto floatValue = qtnCreateProperty<QtnPropertyFloat>(m_propertySet);
		floatValue->setName("value");
		floatValue->setDisplayName(tr("Value"));
		floatValue->setDescription(tr("Float value"));
		floatValue->setMaxValue(1.f);
		floatValue->setMinValue(0.f);
		floatValue->setStepValue(0.1f);
		floatValue->setValue(0.3f);

		auto textColor = qtnCreateProperty<QtnPropertyQColor>(m_propertySet);
		textColor->setName("textColor");
		textColor->setDisplayName(tr("TextColor"));
		textColor->setDescription(tr("Foreground text color"));
		textColor->setValue(QColor(0, 0, 0));

		qtnP->setPropertySet(m_propertySet);

		this->setCentralWidget(qtnP);
	}

private:
};

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
	QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

	QApplication app(argc, argv);

	DemoSimpleWindow w;
	w.show();

	return app.exec();
}