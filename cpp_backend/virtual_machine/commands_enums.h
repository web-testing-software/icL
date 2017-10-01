#ifndef COMMANDS_ENUMS_H
#define COMMANDS_ENUMS_H

// current version 1.0.0

namespace VM {
	enum class Filter {
		Level1	= 0xFF000000,
		Level2	= 0xFFFF0000,
		Level3	= 0xFFFFFF00,
		Level4	= 0xFFFFFFFF
	};

	enum class Command {
		Language	= 0x01000000,
		Browser		= 0x02000000,
		Driver		= 0x03000000,
		JavaScript	= 0x04000000,
		Input		= 0x05000000,
		DataBase	= 0x06000000,
		Debugger	= 0x07000000
	};

	namespace Language {
		enum class Command {
			Control			= 0x01010000,
			LocalMemory		= 0x01020000,
			StateStorange	= 0x01030000,
			Constant		= 0x01040000,
			BoolOperator	= 0x01050000
		};

		namespace Control {
			enum class Command {
				SingleShot	= 0x01010100,
				MultiShot	= 0x01010200,
				Comment		= 0x01010300
			};

			namespace SingleShot {
				enum class Command  {
					If		= 0x01010101,
					BeginIf = 0x01010102,
					Else	= 0x01010103,
					EndIf	= 0x01010104
				};
				}

			namespace Comment {
				enum class Command {
					Delimiter	= 0x01010301,
					Line		= 0x01010302,
					MultiLine	= 0x01010303
				};
				}
			}

		namespace LocalMemory {
			enum class Commands {
				Read	= 0x01020100,
				Write	= 0x01020200
			};

			namespace Read {
				enum class Command {
					Boolean		= 0x01020101,
					Int			= 0x01020102,
					Double		= 0x01020103,
					String		= 0x01020104,
					StringList	= 0x01020105,
					WebElement	= 0x01020106
				};
				}

			namespace Write {
				enum class Command {
					Boolean		= 0x01020201,
					Int			= 0x01020202,
					Double		= 0x01020203,
					String		= 0x01020204,
					StringList	= 0x01020205,
					WebElement	= 0x01020206
				};
				}
			}

		namespace StateStorange {
			enum class Commands {
				Read	= 0x01030100,
				Write	= 0x01030200
			};

			namespace Read {
				enum class Command {
					Boolean		= 0x01030101,
					Int			= 0x01030102,
					Double		= 0x01030103,
					String		= 0x01030104,
					StringList	= 0x01030105
				};
				}

			namespace Write {
				enum class Command {
					Boolean		= 0x01030201,
					Int			= 0x01030202,
					Double		= 0x01030203,
					String		= 0x01030204,
					StringList	= 0x01030205
				};
				}
			}

		namespace Constant {
			enum class Command {
				Read = 0x01040100
			};

			namespace Read {
				enum class Command {
					Boolean		= 0x01040101,
					Int			= 0x01040102,
					Double		= 0x01040103,
					String		= 0x01040104,
					StringList	= 0x01040105
				};
				}
			}

		namespace BoolOperator {
			enum class Command {
				Logical		= 0x01050100,
				Equal		= 0x01050200,
				NotEqual	= 0x01050300,
				StringList	= 0x01050400
			};

			namespace Logical {
				enum class Command {
					Not = 0x01050101,
					And = 0x01050102,
					Or	= 0x01050103,
					XOr = 0x01050104
				};
				}

			namespace Equal {
				enum class Command {
					Boolean		= 0x01050201,
					Int			= 0x01050202,
					Double		= 0x01050203,
					String		= 0x01050204,
					StringList	= 0x01050205
				};
				}

			namespace NotEqual {
				enum class Command {
					Boolean		= 0x01050301,
					Int			= 0x01050302,
					Double		= 0x01050303,
					String		= 0x01050304,
					StringList	= 0x01050305
				};
				}

			namespace StringList {
				enum class Command {
					Contains			= 0x01050401,
					ContainsFragment	= 0x01050402
				};
				}
			}
		}

	namespace Browser {
		// To be completed in next version
		}

	namespace Driver {
		enum class Command {
			Navigation		= 0x03010000,
			ManageContent	= 0x03020000
		};

		namespace Navigation {
			enum class Command {
				Navigation	= 0x03010100,
				Wainting	= 0x03010200
			};

			namespace Navigation {
				enum class Command {
					GoToURL					= 0x03010101,
					OpenLink				= 0x03010102,
					OpenLinkInCurrentTab	= 0x03010103,
					OpenLinkInNewTab		= 0x03010104
				};
				}

			namespace Wainting {
				enum class Command {
					PrepareWaitForPageLoad		= 0x03010201,
					WaitForPageLoad				= 0x03010202,
					WaitForElement				= 0x03010203,
					PrepareWaitForTitleChange	= 0x03010204,
					WaitForTitleChange			= 0x03010205,
					WaitForAjaxEnd				= 0x03010206
				};
				}
			}

		namespace ManageContent {
			enum class Command {
				Frames = 0x03020100
			};

			namespace Frames {
				enum class Frames {
					SwitchToFrame	= 0x03020101,
					SwitchToDefault = 0x03020102
				};
				}
			}
		}

	namespace JavaScript {
		enum class Command {
			BaseJS	= 0x010000,
			DOM		= 0x020000
		};

		namespace BaseJS {
			enum class Command {
				RunJS	= 0x04010100,
				Get		= 0x04010200,
				Set		= 0x04010300
			};

			namespace RunJS {
				enum class Command {
					RunString	= 0x04010101,
					RunFile		= 0x04010102
				};
				}

			namespace Get {
				enum class Command {
					Boolean		= 0x04010201,
					Int			= 0x04010202,
					Double		= 0x04010203,
					String		= 0x04010204,
					StringList	= 0x04010205
				};
				}

			namespace Set {
				enum class Command {
					Boolean		= 0x04010301,
					Int			= 0x04010302,
					Double		= 0x04010303,
					String		= 0x04010304,
					StringList	= 0x04010305
				};
				}
			}

		namespace DOM {
			enum class Command {
				FindElements	= 0x04020100,
				FilterElements	= 0x04020200,
				ElementsTest	= 0x04020300
			};

			namespace FindElements {
				enum class Command {
					Query		= 0x04020101,
					QueryAll	= 0x04020102
				};
				}

			namespace FilterElements {
				enum class Command {
					ByCSSSelector	= 0x04020201,
					ByContent		= 0x04020202
				};
				}

			namespace ElementsTest {
				enum class Command {
					IsVisible	= 0x04020301,
					GetX		= 0x04020302,
					GetY		= 0x04020303
				};
				}
			}
		}

	namespace Input {
		enum class Command {
			Mouse		= 0x05010000,
			Keyboard	= 0x05020000
		};

		namespace Mouse {
			enum class Command {
				BaseEvent		= 0x05010100,
				ComplexEvent	= 0x05010200
			};

			namespace ComplexEvent {
				enum Command {
					Click = 0x05010201
				};
				}
			}

		namespace Keyboard {
			enum Command {
				BaseEvent		= 0x05020100,
				ComplexEvent	= 0x05010100
			};

			namespace ComplexEvent {
				enum class Command {
					SendKey = 0x05020201
				};
				}
			}
		}

	namespace DataBase {
		enum class Command {
			Basic = 0x06010000
		};

		namespace Basic {
			enum class Command {
				Output	= 0x06010100,
				Editing = 0x06010200
			};

			namespace Output {
				enum class Command {
					Select		= 0x06010101,
					SelectAll	= 0x06010102
				};
				}

			namespace Editing {
				enum class Command {
					Update	= 0x06010201,
					Insert	= 0x06010202,
					Delete	= 0x06010203
				};
				}
			}
		}

	namespace Debugger {
		enum class Command {
			Basic = 0x07010000
		};

		namespace Basic {
			enum class Command {
				Focus = 0x07010100
			};

			namespace Focus {
				enum class Command {
					Command			= 0x07010101,
					LoopInit		= 0x07010102,
					LoopCondition	= 0x07010103,
					LoopStep		= 0x07010104
				};
				}
			}
		}
	}

#endif // COMMANDS_ENUMS_H
