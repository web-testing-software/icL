#ifndef COMMANDS_ENUMS_H
#define COMMANDS_ENUMS_H

// current version 1.0.0

namespace vm {

	enum class Filter {
		LEVEL1	= 0x7F000000,
		LEVEL2	= 0x7FFF0000,
		LEVEL3	= 0x7FFFFF00,
		LEVEL4	= 0x7FFFFFFF
	};

	enum class Command {
		LANGUAGE	= 0x01000000,
		BROWSER		= 0x02000000,
		DRIVER		= 0x03000000,
		JAVASCRIPT	= 0x04000000,
		INPUT		= 0x05000000,
		DATABASE	= 0x06000000,
		DEBUGGER	= 0x07000000
	};

	namespace language {
		enum class Command {
			CONTROL			= 0x01010000,
			LOCAL_MEMORY	= 0x01020000,
			STATE_STORANGE	= 0x01030000,
			CONSTANT		= 0x01040000/*,
			BOOL_OPERATOR	= 0x01050000*/
		};

		namespace control {
			enum class Command {
				SINGLE_SHOT	= 0x01010100,
				MULTI_SHOT	= 0x01010200,
				COMMENT		= 0x01010300
			};

			namespace singleshot {
				enum class Command  {
					IF				= 0x01010101,
					BEGIN_IF		= 0x01010102,
					ELSE			= 0x01010103,
					UNEXPECTED_END	= 0x01010104,
					SUCCESS			= 0X01010105,
					FAILED			= 0x01010106,
					EMPTY_STACK		= 0x01010107,
					OPEN_STACK		= 0x01010108,
					DROP_STACK		= 0x01010109
				};
				}

			namespace comment {
				enum class Command {
					DELIMITER	= 0x01010301,
					LINE		= 0x01010302,
					MULTILINE	= 0x01010303
				};
				}
			}

		namespace localmemory {
			enum class Command {
				READ	= 0x01020100,
				WRITE	= 0x01020200
			};

			namespace read {
				enum class Command {
					BOOLEAN		= 0x01020101,
					INT			= 0x01020102,
					DOUBLE		= 0x01020103,
					STRING		= 0x01020104,
					STRING_LIST	= 0x01020105,
					WEB_ELEMENT	= 0x01020106
				};
				}

			namespace write {
				enum class Command {
					BOOLEAN		= 0x01020201,
					INT			= 0x01020202,
					DOUBLE		= 0x01020203,
					STRING		= 0x01020204,
					STRING_LIST	= 0x01020205,
					WEB_ELEMENT	= 0x01020206
				};
				}
			}

		namespace statestorange {
			enum class Command {
				READ	= 0x01030100,
				WRITE	= 0x01030200
			};

			namespace read {
				enum class Command {
					BOOLEAN		= 0x01030101,
					INT			= 0x01030102,
					DOUBLE		= 0x01030103,
					STRING		= 0x01030104,
					STRING_LIST	= 0x01030105
				};
				}

			namespace write {
				enum class Command {
					BOOLEAN		= 0x01030201,
					INT			= 0x01030202,
					DOUBLE		= 0x01030203,
					STRING		= 0x01030204,
					STRING_LIST	= 0x01030205
				};
				}
			}

		namespace constant {
			enum class Command {
				READ = 0x01040100
			};

			namespace read {
				enum class Command {
					BOOLEAN		= 0x01040101,
					INT			= 0x01040102,
					DOUBLE		= 0x01040103,
					STRING		= 0x01040104,
					STRING_LIST	= 0x01040105
				};
				}
			}
/*
		namespace booloperator {
			enum class Command {
				LOGICAL		= 0x01050100,
				EQUAL		= 0x01050200,
				NOT_EQUAL	= 0x01050300,
				STRING_LIST	= 0x01050400
			};

			namespace logical {
				enum class Command {
					NOT = 0x01050101,
					AND = 0x01050102,
					OR	= 0x01050103,
					XOR = 0x01050104
				};
				}

			namespace equal {
				enum class Command {
					BOOLEAN		= 0x01050201,
					INT			= 0x01050202,
					DOUBLE		= 0x01050203,
					STRING		= 0x01050204,
					STRING_LIST	= 0x01050205
				};
				}

			namespace notequal {
				enum class Command {
					BOOLEAN		= 0x01050301,
					INT			= 0x01050302,
					DOUBLE		= 0x01050303,
					STRING		= 0x01050304,
					STRING_LIST	= 0x01050305
				};
				}

			namespace stringlist {
				enum class Command {
					CONTAINS			= 0x01050401,
					CONSTAINS_FRAGMENT	= 0x01050402
				};
				}
			}*/
		}

	namespace browser {
		// To be completed in next version
		}

	namespace driver {
		enum class Command {
			NAVIGATION		= 0x03010000,
			MANAGE_CONTENT	= 0x03020000
		};

		namespace navigation {
			enum class Command {
				NAVIGATION	= 0x03010100,
				WAINTING	= 0x03010200
			};

			namespace navigation {
				enum class Command {
					GO_TO_URL					= 0x03010101,
					OPEN_LINK					= 0x03010102,
					OPEN_LINK_IN_CURRENT_TAB	= 0x03010103,
					OPEN_LINK_IN_NEW_TAB		= 0x03010104
				};
				}

			namespace wainting {
				enum class Command {
					PREPARE_WAIT_FOR_PAGE_LOAD		= 0x03010201,
					WAIT_FOR_PAGE_LOAD				= 0x03010202,
					WAIT_FOR_ELEMENT				= 0x03010203,
					PREPARE_WAIT_FOR_TITLE_CHANGE	= 0x03010204,
					WAIT_FOR_TITLE_CHANGE			= 0x03010205,
					WAIT_FOR_AJAX_END				= 0x03010206
				};
				}
			}

		namespace managecontent {
			enum class Command {
				FRAMES = 0x03020100
			};

			namespace frames {
				enum class Command {
					SWITCH_TO_FRAME	  = 0x03020101,
					SWITCH_TO_DEFAULT = 0x03020102
				};
				}
			}
		}

	namespace javascript {
		enum class Command {
			BASE_JS	= 0x010000,
			DOM		= 0x020000
		};

		namespace basejs {
			enum class Command {
				RUN_JS	= 0x04010100,
				GET		= 0x04010200,
				SET		= 0x04010300
			};

			namespace runjs {
				enum class Command {
					RUN_STRING		= 0x04010101,
					RUN_FILE		= 0x04010102
				};
				}

			namespace get {
				enum class Command {
					BOOLEAN		= 0x04010201,
					INT			= 0x04010202,
					DOUBLE		= 0x04010203,
					STRING		= 0x04010204,
					STRING_LIST	= 0x04010205
				};
				}

			namespace set {
				enum class Command {
					BOOLEAN		= 0x04010301,
					INT			= 0x04010302,
					DOUBLE		= 0x04010303,
					STRING		= 0x04010304,
					STRING_LIST	= 0x04010305
				};
				}
			}

		namespace dom {
			enum class Command {
				FIND_ELEMENTS	= 0x04020100,
				FILTER_ELEMENTS	= 0x04020200,
				ELEMENTS_TEST	= 0x04020300
			};

			namespace findelements {
				enum class Command {
					QUERY		= 0x04020101,
					QUERY_ALL	= 0x04020102
				};
				}

			namespace filterelements {
				enum class Command {
					BY_CSS_SELECTOR	= 0x04020201,
					BY_CONTENT		= 0x04020202
				};
				}

			namespace elementstest {
				enum class Command {
					IS_VISIBLE	= 0x04020301,
					GET_X		= 0x04020302,
					GET_Y		= 0x04020303
				};
				}
			}
		}

	namespace input {
		enum class Command {
			MOUSE		= 0x05010000,
			KEYBOARD	= 0x05020000
		};

		namespace mouse {
			enum class Command {
				BASE_EVENT		= 0x05010100,
				COMPLEX_EVENT	= 0x05010200
			};

			namespace complexevent {
				enum Command {
					CLICK = 0x05010201
				};
				}
			}

		namespace keyboard {
			enum class Command {
				BASE_EVENT		= 0x05020100,
				COMPLEX_EVENT	= 0x05010100
			};

			namespace complexevent {
				enum class Command {
					SEND_KEY = 0x05020201
				};
				}
			}
		}

	namespace database {
		enum class Command {
			BASIC = 0x06010000
		};

		namespace basic {
			enum class Command {
				OUTPUT	= 0x06010100,
				EDITING = 0x06010200
			};

			namespace output {
				enum class Command {
					SELECT		= 0x06010101,
					SELECT_ALL	= 0x06010102
				};
				}

			namespace editing {
				enum class Command {
					UPDATE		= 0x06010201,
					INSERT		= 0x06010202,
					DELETE_ONCE	= 0x06010203
				};
				}
			}
		}

	namespace debugger {
		enum class Command {
			BASIC = 0x07010000
		};

		namespace basic {
			enum class Command {
				TESTING = 0x07010100
			};

			namespace testing {
				enum class Command {
					REPORT = 0x07010101
				};
				}
			}
		}
	}


#endif // COMMANDS_ENUMS_H
