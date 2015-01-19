# include <Siv3D.hpp>

struct Item
{
	String text;
	Point position;
	Color color;
};

void Main()
{
	const Font font(20);
	const CSVReader csv(L"example.csv");

	if (!csv)
	{
		MessageBox::Show(L"�G���[", L"example.csv �̓ǂݍ��݂Ɏ��s���܂����B");
		return;
	}

	Println(L"CSV �̍s��: ", csv.rows);

	Println(L"CSV �� 0 �s�ڂ̗�: ", csv.columns(0));

	// 0 �s�ځA0 ��̗v�f
	const unsigned itemCount = csv.get<unsigned>(0, 0);

	vector<Item> items;

	for (unsigned i = 0; i < itemCount; ++i)
	{
		Item item;
		item.text = csv.get<String>(1, i);
		item.position = csv.get<Point>(2, i);
		item.color = csv.get<Color>(3, i);
		items.push_back(item);
	}

	while (System::Update())
	{
		for (const auto& item : items)
		{
			font(item.text).draw(item.position, item.color);
		}
	}
}